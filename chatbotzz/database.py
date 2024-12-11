import sqlite3

def init_db():
    conn = sqlite3.connect('finance_bot.db')
    c = conn.cursor()
    c.execute('''
        CREATE TABLE IF NOT EXISTS budget (
            id INTEGER PRIMARY KEY AUTOINCREMENT,
            amount REAL NOT NULL,
            category TEXT NOT NULL
        )
    ''')
    conn.commit()
    conn.close()

def add_budget_entry(amount, category):
    conn = sqlite3.connect('finance_bot.db')
    c = conn.cursor()
    c.execute('INSERT INTO budget (amount, category) VALUES (?, ?)', (amount, category))
    conn.commit()
    conn.close()

def get_budget_entries():
    conn = sqlite3.connect('finance_bot.db')
    c = conn.cursor()
    c.execute('SELECT * FROM budget')
    entries = c.fetchall()
    conn.close()
    return entries