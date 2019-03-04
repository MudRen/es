// This is a room for storage eqs , and can filter some "garbage"
//       by Indra@EasternStories
//
//    This is ver2.0 with receive_object(), release_object()

#include <mudlib.h>

inherit ROOM;

int AMOUNT = 0 ;
nomask int my_clean_func(object it) ;

void create()
{
	::create();
        set_short("��׼������");
	set_long(
@C_LONG_DESCRIPTION
�����������ı�׼���ᴢ���ҡ�ǽ�����Ÿ�ʾ(note)��
C_LONG_DESCRIPTION
	);

	set( "light", 1 );
        set( "item_desc", ([
 		"note": "������������������������������Ҫ���ʵ�,�ռ�����\n"
 		        "�벻Ҫ�������Ѱ�Ķѷ�����;�Ķ�����\n" 
 		           ]) );
	set( "exits", ([ 
		"out" : "/d/healer/building/healer_guild"
		       ]) ) ;

	//	     
	//���¸��趨��� arch ���Լ���Ҫ������״�����޸�...
        //
        set("no_clean_array",({ }) ) ;       //����ǿ�Ʋ��������Ʒ(ID)
         		     
        set("max_amount",60) ;	             //�����������������������ֵ 
	set("class_name","NONE") ;           //����������ڹ�������, �������
	                                     //�ù����Ա�����õ�װ��.
        
        //�����ֱ�����������֮WC,damƽ��ֵ
        
	set("weapon_res",({23,17}) ) ; 

	//ÿ���ͱ����֮ac,db�������ֵ,����Ϊ ac+db ֮�� 
        //����ܸı�AC DB��,���ڷ��� set("no_clean",1)
        
        set("armor_res",([                          
                         "body" : 20   , "legs"   : 7 ,
 	                 "feet" : 7    , "cloak"  : 7 , 
 	                 "head" : 7    , "arms"   : 6 , 
 	                 "misc" : 5    , "finger" : 5 , 
 	                 "hands" : 6   , "globe"  : 10 , 
 	                 "shield" : 7  , "saddle" : 9 , 
 	                 "kernal" : 6  , "tail"   : 7 ,
 	                 "others" : 7,
 	                 ]) ) ;
	
	//����������
	set("container_res",200) ;
	
        // �����������ѶϢ, �б�Ҫ�Ļ�����д string cleaning_msg()
	set("clean_msg",
	    "�����ҹ���Ա%s����ҡ��ҡ��˵:����û�õĶ������ⲻ̫�ðɡ�\n") ;
	set("msg_arg","����֮��") ;
	set("clean_msg1",
	    "�����ҹ���Ա%s�����:���̫�ණ����, ������һ����ٷš�\n") ;
	set("msg_arg1","����֮��") ;
	
	
//	reset();
}

int query_amount(){ return AMOUNT ; }

int realease_object(object ob)
{
    if(living(ob)) return 1;
    AMOUNT-- ;
    return 1 ;
}

int receive_object(object arg)
{
    int result ;
    string msg ;
//    ::receive_object(arg) ;   
    if(living(arg)) return 1 ;    
    
    if( AMOUNT >(int)query("max_amount") ) 
       {
           tell_object(this_player(),
                       sprintf(query("clean_msg1"),query("msg_arg1"))) ;     
           return 0 ;
        }
    result = my_clean_func(arg) ;
    if(result)
      {
         AMOUNT++ ;
         return 1 ;
      }
    else
      {  
         msg = sprintf(query("clean_msg"),query("msg_arg")) ; 
         tell_object(this_player(),msg) ;     
         return 0 ;
      }
}

nomask int my_clean_func(object it)          // ��ֹ����������..
{
     int res1,res2,temp1,temp2,temp3,flag ;    // һ�ѱ���..
     string type,inherit_from,ob_sort ;

     flag = 0 ;
     res1=res2=temp1=temp2=temp3=0 ;        // ��check ��Ʒ������.
                                            // ��inherit list ����ֻ
     inherit_from = inherit_list(it)[0] ;   // ����Ʒ�������趨��������
     ob_sort = "/"+explode(inherit_from,".")[0] ;      
  
     switch(ob_sort)
       {
          case LIVING :
                        flag = 1 ;
                        break ;
          case WEAPON :
                        temp1 = it->query("weapon_class") ;
                        temp2 = it->query("max_damage") ;
                        temp3 = it->query("min_damage") ;
                        res1 = query("weapon_res")[0] ;
                        res2 = query("weapon_res")[1] ;
                        
                        if((temp1>res1)&&((temp2+temp3)>res2*2) )
                           flag = 1 ;
                        break ;
          case ARMOR  :                
                        temp1 = it->query("armor_class") ;
                        temp2 = it->query("defense_bonus") ;
                        type = it->query("type") ;
                        res1 = query("armor_res/"+type) ;
                        if(!res1) res1 = query("armor_res/others");
                   
                        if((temp1+temp2)>res1)
                           flag = 1 ;
                        break; 
          case CONTAINER :                
                        temp1 = it->query("max_load") ; 
                        res1 = query("container_res") ;
                        
                        if(temp1>res1 )
                            flag = 1 ;
                        break; 
          default : flag = 1 ;
                    break ;  
         }   
     return flag ;
}

int clean_up() 
{
     return 0;
}

