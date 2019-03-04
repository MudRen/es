#include "../almuhara.h"

inherit WEAPON;

void create()
{
    set_name("Tien-Shi baton","��ʦ��");
    add("id",({"ling","baton"}) );
    set_short("��ʦ��");
    set_long(
           "���ǰ���ҫ����ɫ��������ƣ���˵���ɴ�˵�е�����ɽ����ʦ�Ե�ĸ��\n"
           "Ӣ������ɽ�����������ɡ�����ʦ���Զ����ʱ�佫�����������ע���\n"
           "�ڣ�ʹ���Ϊһ�Ѿ��о޴��ƻ�������������춸�����ʦ���꣬���ƺ�Ҳ\n"
           "����ĳ�����ԣ���ѡ���Լ������ˡ�\n");
    set("unit","��");
    set("weapon_class",41);
    set("type","wand");
    set("min_damage",20);
    set("max_damage",38);
    set("cast_times",0);
    set("weight",50);
    set("value",({50,"platinum"}));
    set("hit_func","wand_damage");
    set("special_damage",60);
    set("special_c_msg","�ӳ�һƬ���⣬������");
    set("no_sale",1);

}

int stop_wield()
{
	object holder;
	int my_ali;
	
	holder = this_player();
	my_ali = (int)holder->query("alignment");
	if (my_ali > 20000 ) 
		return 0;
	else if (my_ali < -20000 )
		return 0;
	else {
		notify_fail( 
		"��ʦ��ͻȻ���ͨ�죬һ����������ղ�ס����\n" 
			);
		return 1;
	}
}
int wand_damage(object victim,int damage)
{
    object holder,*ob;
    int my_kar,vic_kar,dam,my_sp,my_wand,my_ali,i;

    string c_msg,msg;
    
    if( !victim ) return 0;
    if( !(holder = environment(this_object())) || !living(holder) ) 
        return 0;
        
    my_kar  =(int)holder->query_stat("kar");
    vic_kar =(int)victim->query_stat("kar");
    my_sp   =(int)holder->query("spell_points") ; 
    my_wand =(int)holder->query_skill("wand") ;
    my_ali  =(int)holder->query("alignment");
        
    if(!(dam = (int)this_object()->query("special_damage")) ) 
            return 0 ;
    if( random(vic_kar)>random(my_kar/2) )  return 0;
    if(	(int)holder->query("npc")==1 && random(5) < 2 ) return 0;

// special attack for this baton only....:P
    if( (my_wand > 89 && random(5) < 2 && my_ali < -40000) || ((int)holder->query("npc")==1 && random(3) < 2)  )
     {
    	ob = all_inventory(victim);
                i = sizeof(ob);
                while(i--) {
                        if( !ob[i]->query("equipped") ) continue;
                        if( undefinedp(ob[i]->query("armor_class")) &&
                            undefinedp(ob[i]->query("defense_bonus")) )
                                continue;
                             break;   }
                            if ( i < 0 ) return 0;
    	if( ((int)holder->query("max_load") - (int)holder->query("load")) < (int)ob[i]->query("weight") )
    		return 0;
    	tell_object( holder, 
    		"\n"+"��ʦ���ϵķ��俪ʼ��ã����ܵĿ���������Ŷ���ͻȻһ������������������ !! \n");     
 	tell_room( environment(holder), 
 		"\n"+"��ʦ���ϵķ��俪ʼ��ã���"+holder->query("c_name")+"���ܵĿ���ͻȻ������Ŷ� !!\n",
		holder );
        ob[i]->move(holder);
       return 1;
    }  
    else {
    
    c_msg = (string)query("special_c_msg");
    
    if(my_sp<40)
        { 
          tell_object(holder ,
	        "�����ʦ���΢���Ĺ�â���ƺ��е��������ġ�\n");
          return 0 ;
         }  
		       
    holder->set("spell_points",my_sp-40) ;
    victim->receive_damage( dam );
    victim->set("last_attacker", holder );                       
                
    tell_object( holder,
           "\n\n���"+query("c_name")+c_msg+victim->query("c_name")+"\n");

    tell_room( environment(holder), 
	   "\n"+holder->query("c_name") + "��"+query("c_name")
		 +c_msg+victim->query("c_name")+"\n",
 	    holder );
 	    
    return dam; 
    } 
}	

