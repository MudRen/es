#include "mudlib.h"

inherit WEAPON;

int damage_count=0;
void create()
{
       set_name("ru-lai rope","������");
       add("id",({"so","rope",}) );
       set_short("������");
	   set_long(@C_LONG
����Ϊ����֮һ��,��������������������,ֹͣ���˵Ĺ���... 
��������������ʹ�õķ���,�������������������æ 
C_LONG
	);
	
	set( "unit", "��" );
 	set( "weapon_class", 20 );
        set("type","whip");

        set("second",1);
        set_c_verbs(({ "%s৵�һ����%s��ȥ","%sѸ�ٵ���%s��ȥ" 
  
         }));

	set( "min_damage", 12 );
	set( "max_damage", 20 );
	set( "weight", 50 );
	set( "value", ({ 180, "gold" }) );
//    set("hit_func","tie_enemy");
    set("special_damage",1);
    set("special_c_msg",
"�򱱷�һ��,�����������˵�Х��... ��ʱ��ػ谵������... \n"
"��������е���ͷ�������������ٻ�����,����ס���ĵ���!!! \n\n "

);
}

int tie_enemy(object victim,int damage)
{
    object holder;
    int my_kar,vic_kar,dam;
    string c_msg;
    
    if( !victim ) return 0;
	if( !(holder = environment(this_object())) || !living(holder) ) return 0;
	if( random(18)==7   )
		return 0;
	else {
		c_msg = (string)query("special_c_msg");
		victim->block_attack(4);
                victim->set_temp("msg_stop_attack", 
                "(�㱻��ͷ����������ס,�޷�����)\n");

                  victim->set("last_attacker", holder );
		if( !c_msg ) return 0;
		tell_object( holder, 
			"\n���"+query("c_name")+c_msg+"\n");
		tell_room( environment(holder), 
			holder->query("c_cap_name") + "��"+query("c_name")+c_msg+"\n",
			holder );
     }
	
}	