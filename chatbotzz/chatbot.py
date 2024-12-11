# import cohere
# from database import init_db, add_budget_entry, get_budget_entries

# # Initialize Cohere with your API key
# co = cohere.Client('fF95UJUu0LlwXWLt1TLULOBbKW2SJYeIr9xTWXu3')

# # Initialize the database
# init_db()

# def get_chat_response(user_input):
#     try:
#         response = co.generate(
#             model='command-xlarge-nightly',
#             prompt=f"User: {user_input}\nBot:",
#             max_tokens=50,
#             temperature=0.7,
#             stop_sequences=["User:", "Bot:"]
#         )
#         return response.generations[0].text.strip()
#     except cohere.CohereError as e:
#         return f"Error: {str(e)}"

# def track_budget(amount, category):
#     add_budget_entry(amount, category)

# def show_budget():
#     entries = get_budget_entries()
#     if not entries:
#         return "No budget entries found."
    
#     return "\n".join([f"Amount: {entry[1]}, Category: {entry[2]}" for entry in entries])

# def chatbot():
#     print("Chatbot is ready! Type 'exit' to quit.")
    
#     while True:
#         user_input = input("You: ")

#         if user_input.lower() == 'exit':
#             print("Chatbot: Goodbye!")
#             break

#         # Check for budget tracking commands
#         if user_input.startswith("track budget"):
#             try:
#                 _, amount, category = user_input.split()
#                 track_budget(float(amount), category)
#                 print("Chatbot: Budget tracked successfully.")
#             except ValueError:
#                 print("Chatbot: Please provide valid input in the format 'track budget <amount> <category>'.")
#             continue
        
#         if user_input.lower() == "show budget":
#             print("Chatbot:", show_budget())
#             continue

#         bot_response = get_chat_response(user_input)
#         print(f"Chatbot: {bot_response}")

# if __name__ == "__main__":
#     chatbot()








# import cohere

# # Test your API key
# try:
#     co = cohere.Client('fF95UJUu0LlwXWLt1TLULOBbKW2SJYeIr9xTWXu3')
#     response = co.generate(
#         model='command-xlarge-nightly',
#         prompt='Test prompt',
#         max_tokens=10
#     )
#     print("API key is valid!")
# except cohere.CohereError as e:
#     print(f"API key error: {str(e)}")
    
    
    
    
    
    
# import os
# import cohere

# # Check if the environment variable is being retrieved correctly
# print("API Key from Environment Variable:", os.getenv('COHERE_API_KEY'))

# # If the key is None or empty, handle it appropriately
# api_key = os.getenv('COHERE_API_KEY')
# if not api_key:
#     raise ValueError("COHERE_API_KEY is not set properly in the environment")

# co = cohere.Client(api_key)

import os

print("API Key from Environment Variable:", os.getenv('COHERE_API_KEY'))