// This is a room for storage eqs , and can filter some "garbage"
//       by Indra@EasternStories
//
// This one is Ver1.1 use call_other , and old ver(ver1.0) use call_out
//

#include <mudlib.h>
#define DROP "/cmds/std/_drop.c"
#define GET "/cmds/std/_get.c"

inherit ROOM;

int AMOUNT = 0 ;
int COUNT = 0 ;
nomask int my_clean_func() ;
string cleaning_msg() ;

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
		     
        set("max_amount",50) ;	             //�����������������������ֵ 
	set("class_name","NONE") ;           //����������ڹ�������, �������
	                                     //�ù����Ա�����õ�װ��.
        
        //�����ֱ�����������֮WC,damƽ��ֵ
        
	set("weapon_res",({23,17}) ) ; 

	//ÿ���ͱ����֮ac,db�������ֵ,����Ϊ ac+db ֮�� 
        //����ܸı�AC DB��,���ڷ��� set("no_clean",1)
        
        set("armor_res",([                          
                         "body" : 20   , "legs"   : 9 ,
 	                 "feet" : 7    , "cloak"  : 8 , 
 	                 "head" : 7    , "arms"   : 6 , 
 	                 "misc" : 5    , "finger" : 5 , 
 	                 "hands" : 6   , "globe"  : 25 , 
 	                 "shield" : 7  , "saddle" : 11 , 
 	                 "kernal" : 6  , "tail"   : 8 ,
 	                 "others" : 8,
 	                 ]) ) ;
	
	//����������
	set("container_res",200) ;
	
        // �����������ѶϢ, �б�Ҫ�Ļ�����д string cleaning_msg()
	set("clean_msg",
	    "%s�߽��������һ��,ҡ��ҡͷ,����һ������,��û�õĶ����ճɻҡ�\n") ;
	set("msg_arg","����֮��") ;
	
	reset();
}

void init()
{
     add_action("do_drop","drop") ;
     add_action("do_get","get") ;
}

int do_get(string arg)
{
    if(GET->cmd_get(arg)==0)              // ֱ��ʹ��������get ����(�������)
         return 0 ;                       // ���ʧ��(0), �򴫻�0.
                                          // ����һ��get �Ķ���(��Һ���)
    if(arg=="all")                        // һ��get all ��Ϊ���get��Ч��
       AMOUNT -= 5 ;
    else 
       AMOUNT -- ;
       
    ( AMOUNT < 0 )? 0 : AMOUNT ;          // ��ĿС�0 ʱ��� 0
    
    return 1 ;
}

int do_drop(string arg)
{
    if(DROP->cmd_drop(arg)==0)            // ͬget
         return 0 ;
 
    if(arg=="all")                        // һ��drop all ��Ϊ���drop ��Ч��
       {                                  // ������һ������ COUNT
          AMOUNT += 5 ;                   // �Է�ֹ�ظ�get all,drop all������
          COUNT++ ;
        }
    else
       AMOUNT++ ;
    
    if( AMOUNT > 25 || COUNT > 8 )
      { 
         this_object()->my_clean_func() ;
         AMOUNT = 0 ;
       }
    return 1 ;
}

nomask int my_clean_func()
{
     object *inv,temp,it ;              // һ�ѱ���..
     int i,number,res1,res2,temp1,temp2,temp3,check_flag ;
     string type,inherit_from,ob_sort ;

     inv = all_inventory(this_object()) ;          // ����check�����еĶ���
     number = sizeof(inv) ;
     
     for(i=0;i<number;i++)
        {
           it = inv[i] ;
           check_flag = 0 ;                       // ��Ʒ���Ƴ�ʼ��
           res1=res2=temp1=temp2=temp3=0 ;        // ��check ��Ʒ������.
                                                  // ��inherit list ����
           inherit_from = inherit_list(it)[0] ;   // ����Ʒ�������趨��������
           ob_sort = "/"+explode(inherit_from,".")[0] ;      

           // if that item have no_clean flag , then skip 
           // ��Һ��� no_clean �趨�ľ�ֱ������..

           if(it->query("no_clean")|| ob_sort==USER ) continue ;
           
           switch(ob_sort)
             {
                case LIVING :
                              check_flag = 1 ; 
                              break ;
                case WEAPON :
                              temp1 = it->query("weapon_class") ;
                              temp2 = it->query("max_damage") ;
                              temp3 = it->query("min_damage") ;
                              res1 = query("weapon_res")[0] ;
                              res2 = query("weapon_res")[1] ;
                              
                              if(((temp1<res1)||((temp2+temp3)<res2*2)) )
                                 check_flag = 1 ;                                 
                              break ;
                case ARMOR  :                
                              temp1 = it->query("armor_class") ;
                              temp2 = it->query("defense_bonus") ;
                              type = it->query("type") ;
                              res1 = query("armor_res/"+type) ;
                              if(!(res1)) res1 = query("armor_res/others");
                         
                              if((temp1+temp2)<res1)
                                  check_flag = 1 ;
                              break; 
                case CONTAINER :                
                              temp1 = it->query("max_load") ; 
                              res1 = query("container_res") ;
                              
                              if(temp1<res1 )
                                  check_flag = 1 ;
                              break; 
                default : check_flag = 1 ;
                          break ;  
              }                          
         
           if(check_flag)
             {
//               tell_room(this_object(),
//                           it->query("c_name")+"�ñ���ȥ��\n",) ;
               it->remove() ;
               }
        }

     inv = all_inventory(this_object()) ;
     number = sizeof(inv) ;
     res1=res2=temp1=temp2=temp3=0 ;     
     res1 = query("max_amount") ;
  
 // �������̫����, ���ò��� .. ����no_clean flag ��Ҳ�����
 // �������Ϊ50,�򵱳��� 75 ��ʱ, ��� 75-50 = 25 ��.ʣ50��
 
     if( number>(res1*3/2) )
        {  
           temp2 = number - res1 ; 
           for( i=number;;--i )
              {
                 if(temp1==temp2) break ;
                 if(living(inv[i])&&!(inv[i]->querry("npc")) )                 
                    continue ;
                    
                 inv[i]->remove() ;
                 temp1++ ;
              } 
         }
//  ��������������ոտ���..
                     
     tell_room(this_object(),cleaning_msg(),) ; 
     return 1 ;     
}

string cleaning_msg()
{
   return sprintf(query("clean_msg"),query("msg_arg")) ;
}

int clean_up() 
{
     return 0;
}

