import re

def solution(new_id):
    new_id = new_id.lower()
    
    new_id = re.sub('[^a-z0-9-_.]', '', new_id)
    
    new_id = re.sub('[.]{2,}', '.', new_id)
    
    new_id = re.sub('^[.]', '', new_id)
    new_id = re.sub('[.]$', '', new_id)
    
    new_id = 'a' if len(new_id) == 0 else new_id
    
    new_id = new_id[0:15] if len(new_id) >= 16 else new_id
    new_id = re.sub('[.]$', '', new_id)
    
    new_id += new_id[-1]*(3-len(new_id)) if len(new_id) <= 2 else ""
    
    return new_id
