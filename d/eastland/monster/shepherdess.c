#include <mudlib.h>

inherit TEACHER;
inherit MONSTER;

void create()
{
	::create();
	set_level(10);
	set_name( "shepherdess", "����Ů" );
	add( "id", ({ "girl" }) );
	set_short( "����Ů" );
	set_long(
		"�㿴��һλЦ��������СŮ�����������չ���Ⱥ����\n"
	);
	set( "race", "human" );
	set( "gender", "female" );
	set( "alignment", 1000 );
	set( "max_hp", 500 );
	set( "hit_points", 500);
	set_perm_stat( "dex", 26 );
	set_perm_stat( "int", 30 );
	set_perm_stat( "kar", 24 );
	set_perm_stat( "pie", 24 );
	set_perm_stat( "str", 6 );
   set_skill( "bo", 100 );
	set_skill( "parry", 100 );
	set_skill( "dodge", 100 );
	set_skill( "anatomlogy", 100 );
	set_skill( "defend", 100 );
	set_temp( "aiming_loc", "vascular" );
	set( "special_defense", ([ "all": 70 ]) );
        set_natural_armor( 80, 20 ) ;
	set_natural_weapon( 100, 13, 22 );

	wield_weapon( "/d/eastland/obj/green_stick" );

	set( "chat_chance", 20 );
	set( "chat_output", ({
		"����Ů���غ���: ������ .... �ɰ���С���� .... ���̵���ݵ� ....\n",
		"����Ůһֻֻ���������İ���\n",
          "����Ů�������: �ɶ�����ǲ�Ҫ͵���ҵ�С��!\n",
		"����Ů���������������Ӱ���棬�����������������һ�׽�����\n"
	}) );
   set_lessons( ([ "bo" : ({ 220, 50 }) ]) );
   set( "inquiry", ([
          "wolf" : "@@ask_wolf",
          "hyaena" : "@@ask_wolf"
   ]) );
}

void ask_wolf(object who)
{
   tell_object( who,
        "����Ů̾��: ������ǳ������Ҳ�ע��ʱ, ͵���ҵ�С��\n"
              "�������ҳ�ȥ, �Ҿͽ���ʹ�ù�����(bo)������\n" );
}

void protect_sheep(object sheep, object thief)
{
	object *sheeps;

	tell_room( environment(), 
		"����Ů������Ⱥǰ�棬���: ι������͵�ҵ��򣿱����Σ�\n"
	 );
	sheeps = (object *)query_temp( "protectees" );
	if( sheeps && member_array(sheep, sheeps)!=-1 ) return;
	add_temp( "protectees", ({ sheep }) );
	sheep->add_temp( "protectors", ({ this_object() }) );
	if( !attackers || member_array(thief, attackers)==-1 )
		kill_ob(thief);
}

int check_trainee(object who)
{
   if( !who->query_temp("killed_wolf") )
   return notify_fail(
     "����Ů˵��: ���ǻ��ڸ����ǻ�, �Ҳ���ר�Ľ�����!\n" );
   return notify_fail(
     "����Ů˵��: ��춴����ǻ�û�ﵽ��ʶ, ����ʱ�����ܽ����κμ��ܡ�\n");
   if( (string)who->query("class")=="adventurer" &&
       (int)who->query_level()> 4 )
   return 1;
   else return notify_fail(
     "����Ů˵: ��ֻ�̹��ʸ��ð������!\n" );
}
