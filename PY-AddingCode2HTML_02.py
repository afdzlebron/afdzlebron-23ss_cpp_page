import os
from bs4 import BeautifulSoup

# Get a list of all the .html files in the current directory
html_files = [f for f in os.listdir() if f.endswith('.html')]

# The lines of code to be inserted
new_lines = '''            <a href="open.html">Open</a>
            <a href="cml.html">CML</a>'''

for file in html_files:
    with open(file, 'r') as f:
        soup = BeautifulSoup(f, 'html.parser')
        
    # Find the <nav> element
    nav = soup.find('nav')
    
    # Find the <a href="blatt10.html">blatt10</a> element
    blatt10 = nav.find('a', {'href': 'blatt10.html'})
    
    # Insert the new lines after the blatt10 element
    blatt10.insert_after(BeautifulSoup(new_lines, 'html.parser'))
    
    # Write the modified HTML back to the file
    with open(file, 'w') as f:
        f.write(str(soup))
