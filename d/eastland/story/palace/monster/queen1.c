#include "../../story.h"
inherit MONSTER ;

void create ()
{
	::create();
	set_level(19);
	set_name( "Queen of the west", "����ĸ����" );
	add ("id", ({"queen"}) );
	set_short( "����ĸ����");
	set_long(@CLONG
����ĸ�������÷�����֬��ò���绨�������񻣬�ι˼����й������̬֮��һ��
��촩�����鱦�������淢�Եø���ʮ�㡣����ĸ���ﱾ��ס����������ɽ���ƹ�
�������̷������ˡ������Х�У�����������ճ������������ŵ��ķ�����ɢ����
�õ����ľ����ѣ�������ǣ��޷�����     
CLONG
	);
	set("race","god");
	set("gender","female");
	set_perm_stat("str", 28 );
        set_perm_stat("dex", 25 );
        set_perm_stat("kar", 30 );
        set_perm_stat("int", 30 );
	set( "alignment", 1000 );
	set( "hit_points", 1000 );
	set( "max_hp", 1000 );
        set( "max_fp",500);
	set_natural_weapon( 13, 25, 50 );
	set_natural_armor( 50, 30 );
        set("aim_difficulty",([ 
    	  "critical":70,"vascular":30,"weakest":30 ]) );
        set("wealth/gold",100);
        set_skill("dodge",100);
        set_skill("parry",100);
        set_skill("blunt",100);
        set_skill("anatomlogy",40);
        set("aiming_loc","weakest");       
        set("tactic_func","my_tactic");
        wield_weapon(SPWEA"queen_weapon");
        equip_armor(SPARM"queen_cape");
        equip_armor(SPARM"queen_boots");
        equip_armor(SPARM"queen_helmet");
        set("queen_f",1);
        set("special_defense",(["all":100,"none":40,"energy":5]));
}

void queen_hurt_all(object env)
{
   int i,max;
   object *atk;
   atk=all_inventory(env);
   max=sizeof(atk);
   for (i=0;i<max;i++) 
      if ( living(atk[i]) && !atk[i]->query("queen_f") )
         atk[i]->receive_damage(60);
}
void queen()
{
   object inv,temp1;
   temp1=find_object_or_load(SPALACE"bridge1");
   inv=environment(this_object());
   tell_object(inv,"\n����ĸ����ͻ�������ĳ�Х��������ɥ�Ƿɣ���\n\n\n");
   tell_object(temp1,"�Ӻ�������ͤ������һ��̶���������ʹ�����ɥ�Ƿɣ���\n");
   queen_hurt_all(inv);
   queen_hurt_all(temp1);
}
int my_tactic()
{
    int i;
    object victim;
    
    if ( !victim=query_attacker() ) return 0;
    if ( random(15) > 1 ) return 0;
    queen();
    return 1;
}
