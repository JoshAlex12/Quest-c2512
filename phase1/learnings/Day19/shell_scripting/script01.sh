#!/bin/bash
echo -n "Hi there, enter a random name: " 
read temp_name
read -p "Enter greetings here:" greeting_text
read -p "Enter name:" name
echo "$greeting_text $name!!!"
