# MAP   
: 키와 값의 쌍을 원소로 저장  
-> generic container   
"동일한 키를 갖는 원소가 중복 저장될 경우 오류 발생"  
  
- dic.insert(make_pair(KEY,VALUE)) /
dic[KEY] = VALUE; 으로 저장
- dtype  var = dic[KEY]  / dtype var = dic.at(KEY)  -> KEY값에 해당하는 VALUE가 var에 저장 
- if( dic.find(VALUE) == dic.end() ) -> VALUE의 키를 찾을 수 없다면 true

