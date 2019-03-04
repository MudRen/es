#include "../tsunami.h"

inherit "/d/eastland/island/war/i_warvalue";
inherit HOME+"magic";


void create()
{
        ::create();
        seteuid(getuid()); 
        set_level(16);
        set_name("Daemon Magician","ʥ��ħ��ʿ");
        add( "id", ({"magician","daemon","mage"}) );
        set_short("ʥ��ħ��ʿ");
        set_long(@LONG
����λʥ��ħ��ʿ��������ս���У��������Դ���Ļ��ϵħ������
���ˣ���ȡʤ����
LONG
                );
        set("unit","λ");
        set("race","daemon");
        set("gender","male");
        set("alignment",-500);
        set("hit_points",350);
        set("max_hp",350);
        set("spell_points",1000);
        set("max_sp",1000);
        set("justice",8);
        set_perm_stat("int",28);
        set_perm_stat("str",15);
        set_perm_stat("dex",25);
        set_perm_stat("kar",25);
        set_perm_stat("pie",20);
        
        set_natural_armor(30,30);
        set_natural_weapon(10,5,20);
        
        set( "special_defense", ([ "all":25,"none":10 ]) );
        set("aim_difficulty",
        ([ "critical":100,"vascular":0,"weakest":60,"ganglion":0 ]) );
        set("killer",1);      
        set( "wealth/gold",100 );
        set( "tactic_func", "cast_spell" );
        set("weight",350);
        
        set_skill("shortblade",80 );
        set_skill("dodge",80);
        set_skill("parry",80);
        set("aiming_loc","ganglion"); 
        
        wield_weapon(TWEP"shortblade1");
        equip_armor(TOBJ"hat1");
        equip_armor(TOBJ"robe1");
}

int cast_spell()
{
        object *victim;
        
        if( !(victim=query_attacker()) ) return 0;
            if( random(20)<3 ) {        
         tell_room( environment(this_object()),
"\nħ��ʿ��Ŀ�������������ģ������ķ��ľ��鰡����ʥ��֮�����徻�����ϵ�а��\n"      
"�ɣ���ֻ�������ֵĻ��򴩹����ֵĺ����ţ��γ�һ�Ź������ "
+victim->query("c_name")+" ���ؿ�......\n");
         victim->receive_special_damage("evil",50);
         report( this_object(),victim );      
               return 1;
       }
        else return 0;
}   

