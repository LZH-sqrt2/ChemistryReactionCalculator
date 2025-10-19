import json

language: str

#following file is found as Main.py
with open("../resources/data/config.json", "r", encoding="utf-8") as file:
    config = json.load(file)
    language = config["language"]

with open("../resources/internationalization/" + language + ".json", "r", encoding="utf-8") as file:
    translation_text = json.load(file)

def translatable_text(text: str) -> str:
    try:
        return translation_text[text]
    except KeyError:
        return text

