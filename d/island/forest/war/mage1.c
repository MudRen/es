#include "../tsunami.h"

inherit "/d/eastland/island/war/i_warvalue";
inherit HOME+"magic";


void create()
{
        ::create();
        seteuid(getuid()); 
        set_level(14);
        set_name("Daemon Magician","��ħ��ʿ");
        add( "id", ({"magician","daemon","mage"}) );
        set_short("��ħ��ʿ");
        set_long(@LONG
����λ��ħ��ʿ��������ս���У��������Դ������ϵħ��������ˣ�
��ȡʤ����
LONG
                );
        set("unit","λ");
        set("race","daemon");
        set("gender","male");
        set("alignment",-300);
        set("hit_points",350);
        set("max_hp",350);
        set("spell_points",1000);
        set("max_sp",1000);
        set("justice",5);        
        set_perm_stat("int",28);
        set_perm_stat("str",12);
        set_perm_stat("dex",20);
        set_perm_stat("kar",20);
        set_perm_stat("pie",15);
        
        set_natural_armor(20,25);
        set_natural_weapon(8,5,30);
        
        set( "special_defense", ([ "all":20,"none":10 ]) );
        set("aim_difficulty",
        ([ "critical":100,"vascular":0,"weakest":60,"ganglion":20 ]) );
        set("killer",1);      
        set( "wealth/gold",70 );
        set( "tactic_func", "cast_spell" );
        set("weight",450);
        
        set_skill("dagger",70);
        set_skill("dodge",70);
        set_skill("parry",70);
        
        wield_weapon(TWEP"dagger2");
        equip_armor(TOBJ"hat2");
        equip_armor(TOBJ"robe2");
}

int cast_spell()
{
        object *victim;
        
        if( !(victim=query_attacker()) ) return 0;
            if( random(20)<3 ) {        
         tell_room( environment(this_object()),
"\n��ħ��ʿ��Ŀ�������������ģ��������������񰡣�����֮ʥ�����ٻ�\n"      
"�ķ�����֮���飭����  ӡ����֮��  ������ֻ������������������Ĺ�\n"
"�������������Ű "+victim->query("c_name")+" ������......\n");
         victim->receive_special_damage("evil",40);
         report( this_object(),victim );      
               return 1;
       }
        else return 0;
}   

