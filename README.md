# AI Chatbot Using Cohere API
## By Subrata Dhibar
Welcome to the AI Chatbot project! This chatbot leverages Cohere's Natural Language Processing (NLP) capabilities to create an intelligent conversational interface. The project is designed for simplicity, extensibility, and ease of integration into various applications.

---

## Features

- **Natural Conversations**: Powered by Cohere’s advanced NLP models.
- **Customizable**: Easily adapt to different use cases with simple configurations.
- **Lightweight**: Minimal dependencies and efficient codebase.
- **Extensible**: Add more features or integrate with other APIs effortlessly.

---

## Requirements

Before running the project, ensure you have the following:

- Python 3.8 or later
- A Cohere API key ([Sign up for free here](https://cohere.ai/))

### Dependencies

Install the required Python libraries:

```bash
pip install cohere flask
```

---

## Setup Instructions

1. **Clone the Repository**:

   ```bash
   git clone https://github.com/your-username/ai-chatbot-cohere.git
   cd ai-chatbot-cohere
   ```

2. **Add Your Cohere API Key**:
   
   - Rename `.env.example` to `.env`:
     ```bash
     mv .env.example .env
     ```
   - Add your API key to the `.env` file:
     ```
     COHERE_API_KEY=your-api-key-here
     ```

3. **Run the Application**:

   ```bash
   python app.py
   ```

4. **Access the Chatbot**:

   Open your browser and navigate to `http://127.0.0.1:5000` to interact with the chatbot.

---

## Code Overview

### `app.py`

The main entry point of the chatbot:

- **Cohere Initialization**:
  ```python
  import cohere
  from flask import Flask, request, jsonify

  app = Flask(__name__)
  co = cohere.Client(api_key="YOUR_API_KEY")
  ```

- **Chat Endpoint**:
  A POST endpoint to handle user input and return AI responses:
  ```python
  @app.route('/chat', methods=['POST'])
  def chat():
      user_input = request.json['message']
      response = co.generate(
          model='command-xlarge-nightly',
          prompt=f"{user_input}",
          max_tokens=50
      )
      return jsonify({'response': response.generations[0].text.strip()})
  ```

---

## How It Works

1. The chatbot takes user input via a web form or API call.
2. The input is sent to Cohere's API using the `generate` method.
3. The response from Cohere is processed and returned to the user.

---

## Customization

- **Change Response Length**:
  Modify the `max_tokens` parameter in `app.py`.
- **Adjust Prompting**:
  Customize the `prompt` parameter to guide the chatbot’s behavior.
- **Enhance Frontend**:
  Use CSS frameworks like Bootstrap to improve the chatbot’s UI.

---

## Contributing

We welcome contributions! Please follow these steps:

1. Fork the repository.
2. Create a new branch: `git checkout -b feature-name`.
3. Commit your changes: `git commit -m 'Add new feature'`.
4. Push to the branch: `git push origin feature-name`.
5. Open a Pull Request.

---

## License

This project is licensed under the MIT License. See the `LICENSE` file for more details.

---

## Acknowledgments

- [Cohere API](https://cohere.ai/) for providing state-of-the-art NLP capabilities.
- [Flask](https://flask.palletsprojects.com/) for making web development easy.

---

Thank you for using the AI Chatbot project! For questions, feel free to open an issue in the repository or contact us directly.

