#include "../asterism.h"

inherit WEAPON;

void create()
{
    set_name("Wand of Ultimate","����֮��");
    add("id",({"wand","ultimate wand"}) );
   set_short("����֮��(����)");
    set_long(
           "���ħ�ȵ������������ܵ�����������������,����ǰ�˲�������һ\n"
           "��ˮ����,�Թ��ഫ���ˮ�����в�����������������.���˵İ��˿���,\n"
           "�����˵Ĺ��ռ���,�ټ��ϵؾ�����ʥħ��,ʹ��ѷ��ȳ�Ϊħ��ʦ����\n"
           "�������������.\n");
    set("unit","��");
    set("weapon_class",40);
    set("type","wand");
    set("damaged",1);    
    set("min_damage",24);
    set("max_damage",37);
    set("used_times",0);
    set("weight",50);
    set("value",({5000,"gold"}));
    set("hit_func","wand_damage");
    set("special_damage",55);
    set("special_msg"," grow a bright,coverd");
    set("special_c_msg","ǰ�˵�ˮ���򷢳�һ��ǿ��,��Χס");
    set("no_sale",1);

}

int wand_damage(object victim,int damage)
{
    object holder;
    int my_kar,vic_kar,dam,my_sp,my_wand,wc,damaged,ran,times;

    string c_msg,msg;
    
    if( !victim ) return 0;
    if( !(holder = environment(this_object())) || !living(holder) ) 
        return 0;
	
    
    	
    my_kar  = (int)holder->query_stat("kar");
    vic_kar =(int)victim->query_stat("kar");
    my_sp   =(int)holder->query("spell_points") ; 
    my_wand =(int)holder->query_skill("wand") ;
    wc      = (int)this_object()->query("weapon_class") ;
    damaged =(int)this_object()->query("damaged") ;          
    times   = query("used_times");           
    ran     = random(35-my_kar) ;
    
    if( (int)holder->query("npc")==1 ) ran = 1 ;
        
    if( 35-my_kar <0) ran = 1 ;
        
    if(!(dam = (int)this_object()->query("special_damage")) ) 
            return 0 ;
                    
    if(!damaged && random(my_wand*2)<ran && times>8 && (int)holder->query("npc")!=1)
        { 
           write( holder,
                "���ˮ���򱻵����õ�,�Ƶ���.\n\n" );
           tell_room( environment(holder), 
                "\n"+holder->query("c_cap_name")+"����"+query("c_name")
                      +"ǰ�˵�ˮ�����ҵ�һ��,����.\n\n",
                holder ) ;     
                        
           this_object()->add("short"," (damaged)") ;
           this_object()->add("c_short"," (����)") ;             
           this_object()->set("weapon_class",3*wc/5) ;
           this_object()->set("min_damage",20) ;
           this_object()->set("max_damage",30) ; 
           this_object()->set("damaged",1);
           return 0 ;
         }        
                         
    if( random(vic_kar)>random(my_kar/4) )  return 0;
    if(	(int)holder->query("npc")==1 && random(3) < 2 ) return 0;

    msg   = (string)query("special_msg");
    c_msg = (string)query("special_c_msg");
    
    if( !c_msg ) c_msg = msg;    
    if( !msg ) return 0;

    if(my_sp<30)
        { 
          tell_object(holder ,
                  "��ķ��������Ծۼ��ؾ�����������.\n" );
          return 0 ;
         }  
		       
    if(!(!damaged))
        {  tell_object(holder ,
                "��������ѵ�ˮ��������һ�������Ĺ�â,Ȼ��������ʧ.\n" );
           tell_room( environment(holder),
                "\n"+holder->query("c_cap_name")+"����"+query("c_name")
                     +"ǰ���Ƶ���ˮ���򷢳�һ�������Ĺ�â,Ȼ��������ʧ\n",
                holder ) ;     
                     
           holder->set("spell_points",my_sp-10) ;                       
           return 0 ;
            }    
                        
    holder->set("spell_points",my_sp-30) ;
    victim->receive_damage( dam );
    victim->set("last_attacker", holder );                       
    this_object()->set("used_times",times+1);
                
   tell_object( holder, 
           "���"+query("c_name")+c_msg+victim->query("c_cap_name")
           +"\n" );

   tell_room( environment(holder), 
	   "\n"+holder->query("c_cap_name") + "��"+query("c_name")
            +c_msg+victim->query("c_cap_name")+"\n",
 	    holder );

   tell_object( victim,
           "\n"+holder->query("c_cap_name") + "��"+query("c_name")
                +c_msg+"��.\n" );
	 
    return dam; 
     
}	

