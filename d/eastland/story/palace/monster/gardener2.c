#include <mudlib.h>
#include "../../story.h"
inherit MONSTER ;
void create ()
{
	::create();
	set_level(17);
	set_name( "Lu-Wu", "½��" );
	add ("id", ({"lu-wu","Lu-Wu"}) );
	set_short( "���� ½��");
	set_long(@CLONG
½�������˵������ϻ������Ӻ���צ������β�ͣ�״ò��Ϊ���͡����ǹ������Ͼ�
�ǵĲ�������񣬻Ƶ�ʱ�������ɰ���Σ��м��鲼ÿ�����䡣��     
CLONG
	);
	set("race","god");
	set("gender","male");
	set_perm_stat("str", 25 );
        set_perm_stat("str", 1 );
        set( "max_hp",5000);
        set( "hit_points",5000);
	set_natural_weapon(100,7,0);
	set_natural_armor( 1, 1 );
        set_skill("dodge",70);
        set_skill("parry",70);
        set_skill("wand",100);
        wield_weapon(SPWEA"dragonwand1");
        equip_armor(SPARM"gardener_ring1");
        set("servant",1);
        set("Hking",1);
        set("defend",100);
        set("tactic_func","my_tactic");
}
int stop_attack()
{
    this_player()->add_temp("kill_huang",1);
    return 0;
}