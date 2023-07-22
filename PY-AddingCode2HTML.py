import os
from bs4 import BeautifulSoup

# Lines to add
lines_to_add = '''
            <a href="open.html">Open</a>
            <a href="cml.html">CML</a>
'''

# Function to modify the HTML file
def modify_html_file(file_path):
    with open(file_path, 'r') as f:
        html_content = f.read()

    soup = BeautifulSoup(html_content, 'html.parser')
    nav_element = soup.find('nav')

    if nav_element:
        blatt10_element = nav_element.find('a', href='blatt10.html')
        if blatt10_element:
            blatt10_element.insert_after(BeautifulSoup(lines_to_add, 'html.parser'))

    with open(file_path, 'w') as f:
        f.write(str(soup))

# Get a list of all HTML files in the current directory
html_files = [file for file in os.listdir('.') if file.endswith('.html')]

# Modify each HTML file
for file_name in html_files:
    modify_html_file(file_name)
