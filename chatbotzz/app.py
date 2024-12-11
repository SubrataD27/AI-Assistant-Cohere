# # app.py
# from flask import Flask, request, render_template, jsonify
# from datetime import datetime
# import cohere
# import sqlite3
# import logging
# from functools import wraps

# app = Flask(__name__)

# # Configure logging
# logging.basicConfig(
#     level=logging.INFO,
#     format='%(asctime)s - %(name)s - %(levelname)s - %(message)s',
#     filename='crop_doctor.log'
# )
# logger = logging.getLogger(__name__)

# # Configuration
# class Config:
#     DATABASE = 'crop_doctor.db'
#     COHERE_API_KEY = 'your_api_key_here'  # Move to environment variable in production
#     MAX_RETRIES = 3
#     RESPONSE_LENGTH = 300

# # Initialize Cohere client
# co = cohere.Client(Config.COHERE_API_KEY)

# # Database initialization
# def init_db():
#     with sqlite3.connect(Config.DATABASE) as conn:
#         conn.execute('''
#             CREATE TABLE IF NOT EXISTS chat_history (
#                 id INTEGER PRIMARY KEY AUTOINCREMENT,
#                 timestamp DATETIME DEFAULT CURRENT_TIMESTAMP,
#                 user_input TEXT NOT NULL,
#                 bot_response TEXT NOT NULL
#             )
#         ''')
#         conn.execute('''
#             CREATE TABLE IF NOT EXISTS crop_data (
#                 id INTEGER PRIMARY KEY AUTOINCREMENT,
#                 crop_name TEXT NOT NULL,
#                 disease TEXT,
#                 symptoms TEXT,
#                 treatment TEXT
#             )
#         ''')

# # Error handling decorator
# def handle_errors(f):
#     @wraps(f)
#     def decorated_function(*args, **kwargs):
#         try:
#             return f(*args, **kwargs)
#         except cohere.CohereError as e:
#             logger.error(f"Cohere API error: {str(e)}")
#             return jsonify({
#                 "status": "error",
#                 "message": "An error occurred while processing your request. Please try again."
#             })
#         except sqlite3.Error as e:
#             logger.error(f"Database error: {str(e)}")
#             return jsonify({
#                 "status": "error",
#                 "message": "A database error occurred. Please try again later."
#             })
#         except Exception as e:
#             logger.error(f"Unexpected error: {str(e)}")
#             return jsonify({
#                 "status": "error",
#                 "message": "An unexpected error occurred. Please try again."
#             })
#     return decorated_function

# # Enhanced context for more specific and detailed responses
# CROP_DOCTOR_CONTEXT = """
# You are Crop Doctor, an AI assistant specialized in agricultural advice. Your responses should be:
# 1. Scientific and evidence-based
# 2. Practical and actionable
# 3. Safety-conscious, especially regarding chemical usage
# 4. Region and climate-aware when possible

# Areas of expertise:
# 1. Plant Disease:
#    - Identification based on symptoms
#    - Treatment recommendations
#    - Prevention strategies

# 2. Pest Control:
#    - Pest identification
#    - Integrated pest management (IPM)
#    - Chemical and biological control methods

# 3. Crop Management:
#    - Growth stage monitoring
#    - Nutrient requirements
#    - Best practices for different crops

# 4. Soil Health:
#    - Soil testing interpretation
#    - Fertilization recommendations
#    - Soil conservation practices

# 5. Irrigation:
#    - Water management
#    - Irrigation scheduling
#    - Efficiency improvement

# Always include safety precautions when discussing chemicals or hazardous materials.
# Format responses with clear sections and bullet points when appropriate.
# """

# def get_cohere_response(user_input):
#     prompt = f"{CROP_DOCTOR_CONTEXT}\n\nUser Query: {user_input}\nCrop Doctor's Response:"
    
#     response = co.generate(
#         model='command-xlarge-nightly',
#         prompt=prompt,
#         max_tokens=Config.RESPONSE_LENGTH,
#         temperature=0.7,
#         k=0,
#         p=0.75,
#         frequency_penalty=0.3,
#         presence_penalty=0.3,
#         stop_sequences=["User Query:", "Crop Doctor's Response:"],
#         return_likelihoods='NONE'
#     )
    
#     return response.generations[0].text.strip()

# def save_chat_history(user_input, bot_response):
#     with sqlite3.connect(Config.DATABASE) as conn:
#         conn.execute(
#             'INSERT INTO chat_history (user_input, bot_response) VALUES (?, ?)',
#             (user_input, bot_response)
#         )

# @app.route('/')
# def home():
#     return render_template('index.html')

# @app.route('/chat', methods=['POST'])
# @handle_errors
# def chat():
#     user_input = request.form['user_input']
    
#     # Input validation
#     if not user_input or len(user_input.strip()) == 0:
#         return jsonify({
#             "status": "error",
#             "message": "Please provide a valid input."
#         })
    
#     # Get response from Cohere
#     response = get_cohere_response(user_input)
    
#     # Save to chat history
#     save_chat_history(user_input, response)
    
#     return jsonify({
#         "status": "success",
#         "message": response
#     })

# @app.route('/chat_history', methods=['GET'])
# @handle_errors
# def get_chat_history():
#     with sqlite3.connect(Config.DATABASE) as conn:
#         cursor = conn.execute(
#             'SELECT timestamp, user_input, bot_response FROM chat_history ORDER BY timestamp DESC LIMIT 50'
#         )
#         history = cursor.fetchall()
        
#     return jsonify({
#         "status": "success",
#         "history": [
#             {
#                 "timestamp": row[0],
#                 "user_input": row[1],
#                 "bot_response": row[2]
#             }
#             for row in history
#         ]
#     })

# # Error handlers
# @app.errorhandler(404)
# def not_found_error(error):
#     return jsonify({
#         "status": "error",
#         "message": "The requested resource was not found."
#     }), 404

# @app.errorhandler(500)
# def internal_error(error):
#     return jsonify({
#         "status": "error",
#         "message": "An internal server error occurred. Please try again later."
#     }), 500

# if __name__ == "__main__":
#     init_db()
#     app.run(debug=False)  # Set to False in production


# app.py
from flask import Flask, request, render_template, jsonify
import cohere
import sqlite3
import logging
from functools import wraps

app = Flask(__name__)

# Configure logging
logging.basicConfig(
    level=logging.INFO,
    format='%(asctime)s - %(name)s - %(levelname)s - %(message)s',
    filename='crop_doctor.log'
)
logger = logging.getLogger(__name__)

# Configuration
class Config:
    DATABASE = 'crop_doctor.db'
    COHERE_API_KEY = 'fF95UJUu0LlwXWLt1TLULOBbKW2SJYeIr9xTWXu3'  # Replace with your actual API key
    MAX_RETRIES = 3
    RESPONSE_LENGTH = 300

# Initialize Cohere client
co = cohere.Client(Config.COHERE_API_KEY)

# Database initialization
def init_db():
    with sqlite3.connect(Config.DATABASE) as conn:
        conn.execute('''
            CREATE TABLE IF NOT EXISTS chat_history (
                id INTEGER PRIMARY KEY AUTOINCREMENT,
                timestamp DATETIME DEFAULT CURRENT_TIMESTAMP,
                user_input TEXT NOT NULL,
                bot_response TEXT NOT NULL
            )
        ''')
        conn.execute('''
            CREATE TABLE IF NOT EXISTS crop_data (
                id INTEGER PRIMARY KEY AUTOINCREMENT,
                crop_name TEXT NOT NULL,
                disease TEXT,
                symptoms TEXT,
                treatment TEXT
            )
        ''')

# Error handling decorator
def handle_errors(f):
    @wraps(f)
    def decorated_function(*args, **kwargs):
        try:
            return f(*args, **kwargs)
        except cohere.CohereError as e:
            logger.error(f"Cohere API error: {str(e)}")
            return jsonify({
                "status": "error",
                "message": "An error occurred while processing your request. Please try again."
            })
        except sqlite3.Error as e:
            logger.error(f"Database error: {str(e)}")
            return jsonify({
                "status": "error",
                "message": "A database error occurred. Please try again later."
            })
        except Exception as e:
            logger.error(f"Unexpected error: {str(e)}")
            return jsonify({
                "status": "error",
                "message": "An unexpected error occurred. Please try again."
            })
    return decorated_function

# Enhanced context for more specific and detailed responses
CROP_DOCTOR_CONTEXT = """
You are Crop Doctor, an AI assistant specialized in agricultural advice. Your responses should be:
1. Scientific and evidence-based
2. Practical and actionable
3. Safety-conscious, especially regarding chemical usage
4. Region and climate-aware when possible

Areas of expertise:
1. Plant Disease:
   - Identification based on symptoms
   - Treatment recommendations
   - Prevention strategies

2. Pest Control:
   - Pest identification
   - Integrated pest management (IPM)
   - Chemical and biological control methods

3. Crop Management:
   - Growth stage monitoring
   - Nutrient requirements
   - Best practices for different crops

4. Soil Health:
   - Soil testing interpretation
   - Fertilization recommendations
   - Soil conservation practices

5. Irrigation:
   - Water management
   - Irrigation scheduling
   - Efficiency improvement

Always include safety precautions when discussing chemicals or hazardous materials.
Format responses with clear sections and bullet points when appropriate.
"""

def get_cohere_response(user_input):
    prompt = f"{CROP_DOCTOR_CONTEXT}\n\nUser Query: {user_input}\nCrop Doctor's Response:"
    
    response = co.generate(
        model='command-xlarge-nightly',
        prompt=prompt,
        max_tokens=Config.RESPONSE_LENGTH,
        temperature=0.7,
        k=0,
        p=0.75,
        frequency_penalty=0.3,
        presence_penalty=0.3,
        stop_sequences=["User Query:", "Crop Doctor's Response:"],
        return_likelihoods='NONE'
    )
    
    return response.generations[0].text.strip()

def save_chat_history(user_input, bot_response):
    with sqlite3.connect(Config.DATABASE) as conn:
        conn.execute(
            'INSERT INTO chat_history (user_input, bot_response) VALUES (?, ?)',
            (user_input, bot_response)
        )

@app.route('/')
def home():
    return render_template('index.html')

@app.route('/chat', methods=['POST'])
@handle_errors
def chat():
    user_input = request.form['user_input']
    
    # Input validation
    if not user_input or len(user_input.strip()) == 0:
        return jsonify({
            "status": "error",
            "message": "Please provide a valid input."
        })
    
    # Get response from Cohere
    response = get_cohere_response(user_input)
    
    # Save to chat history
    save_chat_history(user_input, response)
    
    return jsonify({
        "status": "success",
        "message": response
    })

@app.route('/chat_history', methods=['GET'])
@handle_errors
def get_chat_history():
    with sqlite3.connect(Config.DATABASE) as conn:
        cursor = conn.execute(
            'SELECT timestamp, user_input, bot_response FROM chat_history ORDER BY timestamp DESC LIMIT 50'
        )
        history = cursor.fetchall()
        
    return jsonify({
        "status": "success",
        "history": [
            {
                "timestamp": row[0],
                "user_input": row[1],
                "bot_response": row[2]
            }
            for row in history
        ]
    })

# Error handlers
@app.errorhandler(404)
def not_found_error(error):
    return jsonify({
        "status": "error",
        "message": "The requested resource was not found."
    }), 404

@app.errorhandler(500)
def internal_error(error):
    return jsonify({
        "status": "error",
        "message": "An internal server error occurred. Please try again later."
    }), 500

if __name__ == "__main__":
    init_db()
    app.run(debug=False)  # Set to False in production