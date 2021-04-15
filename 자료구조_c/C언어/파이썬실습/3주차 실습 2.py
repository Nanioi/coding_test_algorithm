text="<strong>$5.04</strong>"
where=text.find('>$')
start=where +1
end=start+5
price=text[start:end]
print(price)
