
#include <../zeus.h>

inherit MONSTER ;

void create ()
{
        ::create();
        set_level(19);
        set_name( "Master", "���ϴ�" );
        add ("id",({ "master"}));
        set_short( "a master of mine","������ˣ����ϴ�");
        set("unit","λ");
        set_long(@C_LONG
�������е������µ�һ����ʦ�Ľ�®���˶����Ĵ�磬���������μ�����
ҵ������**���**����������\��\��\���Լ����˵�ͷ�Բŵ��Խ���Ƭ����
�ۺ�Ŀ�������������
C_LONG
);
        set ("gender", "male");
        set ("race", "dwarf");
        set_natural_armor( 70, 20 );
        set_natural_weapon( 40, 20, 40 );
        set_perm_stat( "str", 30 );
        set_perm_stat( "kar", 25 );
        set_perm_stat( "int", 30 );
        set_perm_stat( "dex", 30 );
        set_skill( "axe", 90 );
        set_skill( "parry", 80 );
        set( "tactic","berserk");
        set( "hit_points", 1200 );
        set( "max_hp", 1200 );
        set( "special_defense", ([ "cold": 40 ]) );
	set( "wealth/gold",100);
	wield_weapon(ZOBJ"/tang_axe");
	equip_armor(ZOBJ"/black_armband");
	equip_armor(ZOBJ"/black_boots");
	equip_armor(ZOBJ"/king_robe");
	equip_armor(ZOBJ"/diamond_ring");
	set("inquiry",([
	"magic magnetite":"@@ask_magic_metal",
	"troll" :
"������������ԭ��������������ħ�������󣬿�����������\n"
"�����˴������ڽ������ռס�����κ������ߣ�ֻҪ���ܰ���ȡ���־Ϳ�\n"
"�Խ���������������һ�Ѿ���������\n" 
]));
}
void ask_magic_metal()
{ 
    tell_object(this_player(),
@ASK

�����汦���е��߾�֮��ֻҪ���ܴ���ң�����ϣ��ɱ������ȡ�ñ��
������Ӯ�ҾͲ�Ҫȥ�����������������ɣ�

ASK
);
     kill_ob(this_player());
     this_player()->set_temp("ask#metal",1);
}
     
void die()
{      object ob,who;
      who=query_current_attacker();
  if(who->query_temp("ask#metal")){ 
tell_room(environment(this_object()),
"\n������Ӯ�ˣ�ϣ�������ҵ����˵����㣬����ɱ�������õ�ħ��������\n"
"����һ�������޵е������������Щװ��������ϣ�����������������ұ���\n"
"ȥ�չ������ˣ������������Ϳ�����������ڵĻ����ˣ�\n\n",
this_object()  );
 set("alt_corpse",ZMOB"/mine_master");
  ob=present("master");
   ob->remove();
::die(1);
}else{
::die(1);
}
}