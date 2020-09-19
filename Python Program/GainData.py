import psycopg2




conn = psycopg2.connect(user = "finalp",
                        password = "12345678",
                        host = "127.0.0.1",
                        port = "5432",
                        database = "fpdb")

cur = conn.cursor()

cur.execute("SELECT * FROM fp_stores_data;")

result = cur.fetchall()


mapONE = {

}
countryMap = {

}

#creating mapONE
for row in result:
   
    if(not(row[7] in mapONE)):
        mapONE[row[7]] = {}
        
        if(not( row[2] in mapONE[row[7]] )):
            (mapONE[row[7]])[row[2]] = [row[5],row[3]]
        else:
            ((mapONE[row[7]])[row[2]])[0] = ((mapONE[row[7]])[row[2]])[0] + row[5]
    else:
        if(not( row[2] in mapONE[row[7]] )):
            (mapONE[row[7]])[row[2]] = [row[5],row[3]]
        else:
            ((mapONE[row[7]])[row[2]])[0] = ((mapONE[row[7]])[row[2]])[0] + row[5]

print("most popular product in every provice\n\t")
#most popular product in every provice
for item in mapONE:
    tmpDIC = mapONE[item]
    max = 0
    id = 0
    price = 0
    for productID in tmpDIC:
        if(((mapONE[item])[productID])[0] > max):
            max = ((mapONE[item])[productID])[0]
            id = productID
            price = ((mapONE[item])[productID])[1]
    countryMap[id] = [item,max,price]
    print(f'in {item}\n\t\tmost popular product is : {id}\n\t\twhich sold {max} number of item\n\t\tand whole profit is : {price*max}')

print("\n\n\n")
#most popular product in whole country 
max = 0 
provice = "someWhere!"
id = 0
price = 0
for item in countryMap:  
    if((countryMap[item])[1] > max):
        max = (countryMap[item])[1]
        provice = (countryMap[item])[0]
        id = item
        price = (countryMap[item])[2]
print("most popular product in whole country\n\t")
print(f'In whole\n\t\tcountry most popular product is : {id}\n\t\twhich sold {max} number of item\n\t\tin {provice}\n\t\tprofit is : {price*max}')

    




   
