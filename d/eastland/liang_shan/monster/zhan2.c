#include "../takeda.h"

inherit MONSTER;

void create ()
{

	::create();
    set_level(14);
    set_name("Zhan Shung","��˳");
    add("id",({"zhan","shung"}) );
    set_short("��˳");
	set_long(@C_LONG
�����������������ˣ�����ѩ��Ҳ��һ����⣬��ͨˮ�ԣ�ˮ���·�������
��ҹ��ˮ���������һ���������ּ澫ͨ���գ�Ϊ��ɽ��կˮ����ͳ�졣
C_LONG
	);
    set("alignment",100);
    set( "gender", "male" );
    set( "race", "human");
    set( "unit", "��" );
    set_perm_stat( "dex",25);
    set_perm_stat( "str",20);
    set_perm_stat( "int",18);
    set_perm_stat( "karma",22);
    set_skill("dagger",60);	
    set_skill("dodge",70);
    set ("max_hp",400);
    set ("hit_points",400);
    set ("time_to_heal",5);
    set ("wealth", ([ "gold":180]) );
    set_natural_weapon(25,13,25);
	set_natural_armor(35,20);
	set ("aim_difficulty",([ "weakest":40,"vascular":30]) );
	set("special_defense", (["magic":30,"none":10]) );
    set ("weight", 400);
    set ("inquiry",([
         "fish" : "@@ask_fish",
         "whirl" : "@@ask_whirl"
         ]));
    equip_armor(TARMOR"fish_skin");
    wield_weapon(TWEAPON"waterdagger");
    equip_armor(TARMOR"hat");
}
void ask_fish()
{
if (!(this_player()->query_temp("fat_quest/fish")) || (int)this_player()->query_temp("fat_quest/fish")<1) {
write(
"��˳˵��: Ҫ�㣬�������ǣ��Լ�����ȥץѽ?\n");
return 0;
}
else write(
"��˳˵��: ��������������������? �ղ�������������һ��ʹ�ߣ������鶼�������ҡ�\n"
"����ÿ�����Ƕ�����һ�����ʵ���Ϻ��ȥ�����ŶԷʶ�Ӧ����Щ������\n");
call_out("suggest_diet",5,this_player());
return 0;
}
int suggest_diet()
{
write(
"����ת�����У���˳ͻȻ��ס���㣬����˵��: \n"
"�������£����б�Ľ��飬���ҵ���������: ���ǲ�ȥ�Ե�ԭ�򣬳���û��\n"
"��֮�⣬�ʶ��ĳ����ǳ��Ĳ���������Ҳ��һ����Ҫ��ԭ��\n\n"
"������˳�Ļ�������ã������ҵ������⣬�跨ά�ֳ��������Ҳ�Ǻ���Ҫ��\n"
"���Ƿʶ��������ܴ�ɨ���Ѳ���Ҫ����ȥ����(diet)��?\n");
this_player()->set_temp("fat_quest/fish",2);
return 0;
}
void ask_whirl()
{
write(
"��˳˵��: ���ߵ���������һ����˵���ں������ס��һֻǧ��Ĵ�Ӱ�\n"
"��������ˮ����ˮʱ���Ͳ����˺��е����У������������Ҳ�����....\n");
return 0;
}
