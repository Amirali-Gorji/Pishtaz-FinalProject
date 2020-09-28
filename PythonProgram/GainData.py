import psycopg2




conn = psycopg2.connect(user = "finalp",
                        password = "12345678",
                        host = "127.0.0.1",
                        port = "5432",
                        database = "fpdb")

cur = conn.cursor()
select = "SELECT * FROM fp_stores_data;"
cur.execute(select)

result = cur.fetchall()


mapONE = {

}
countryMap = {

}

mapTWO = {

}

citiesMap ={

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

print("1-Most popular product in every provice\n\t")
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
    print(f'In {item}\n\t\tmost popular product is : {id}\n\t\twhich sold {max} number of items\n\t\tand total profit is : {price*max}')

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
print("2-Most popular product in whole country\n")
print(f'\tIn whole country\n\t\tmost popular product is : {id}\n\t\twhich sold {max} number of items\n\t\tin {provice}\n\t\tprofit is : {price*max}')

    



#most popular product in every city  
for row in result:
   
    if(not(row[6] in mapTWO)):
        mapTWO[row[6]] = {}
        if( not (row[7] in mapTWO[row[6]])):
            (mapTWO[row[6]])[row[7]] = {}
            if(not( row[2] in (mapTWO[row[6]])[row[7]])):
                ((mapTWO[row[6]])[row[7]])[row[2]] = [row[5],row[3]]
            else:
                (((mapTWO[row[6]])[row[7]])[row[2]])[0] = (((mapTWO[row[6]])[row[7]])[row[2]])[0] + row[5]
        else:
            if(not( row[2] in (mapTWO[row[6]])[row[7]])):
                ((mapTWO[row[6]])[row[7]])[row[2]] = [row[5],row[3]]
            else:
                (((mapTWO[row[6]])[row[7]])[row[2]])[0] = (((mapTWO[row[6]])[row[7]])[row[2]])[0] + row[5]

    else:
        if( not (row[7] in mapTWO[row[6]])):
            (mapTWO[row[6]])[row[7]] = {}
            if(not( row[2] in (mapTWO[row[6]])[row[7]])):
                ((mapTWO[row[6]])[row[7]])[row[2]] = [row[5],row[3]]
            else:
                (((mapTWO[row[6]])[row[7]])[row[2]])[0] = (((mapTWO[row[6]])[row[7]])[row[2]])[0] + row[5]
        else:
            if(not( row[2] in (mapTWO[row[6]])[row[7]])):
                ((mapTWO[row[6]])[row[7]])[row[2]] = [row[5],row[3]]
            else:
                (((mapTWO[row[6]])[row[7]])[row[2]])[0] = (((mapTWO[row[6]])[row[7]])[row[2]])[0] + row[5]
 




print("\n\n\n")
#showin result in every city
print(f'3-Most popular product in every city:\n')
for provice in mapTWO:
    
    for city in mapTWO[provice]:
        max = 0
        tmpID = 0
        price = 0
        for id in (mapTWO[provice])[city]:
            if((((mapTWO[provice])[city])[id])[0] > max ):
                max = (((mapTWO[provice])[city])[id])[0]
                tmpID = id
                price = (((mapTWO[provice])[city])[id])[1]
        print(f'\tIn {provice} , {city}\n\t\tmost popular product is : {tmpID}\n\t\twhich sold {max} number of items\n\t\ttotal profit is : {price*max}')
            




clearRow = "DELETE FROM fp_stores_data;"
cur.execute(clearRow)
