#include "../takeda.h"

inherit MONSTER;

void create()
{
	::create();
	set_level(12);
	set_name( "Sun Er Niang", "�����" );
	add( "id", ({ "sun","er","niang" }) );
	set_short( "�����" );
	set_long(
		"�㿴��һ��ǿ׳���ٸ�����������������ӵ��������ĸҹ�棬��\n"
		"������Ϊ�ޣ�Ϊ��ɽ������Ϣ����������ͷ�졣\n"
	);
	set( "race", "human" );
	set( "gender", "female" );
	set( "alignment", -400 );
	set_perm_stat( "str", 18 );
	set_perm_stat( "dex", 18 );
	set_perm_stat( "kar", 20 );
	set_skill( "shortblade", 50 );
	set_skill( "parry", 60 );
	set_skill( "dodge", 80 );
	set( "wealth/gold", 65 );
	set( "special_defense", (["all": 30 ]) );
	set_natural_weapon( 5, 4, 4 );
	set_natural_armor( 46, 10 );
        set("tactic_func","kick");
	set("inquiry",([
	    "meat" : "@@ask_meat"
	    ]));
	wield_weapon( "/d/eastland/obj/thin_blade" );
        equip_armor(TARMOR"red_skirt");
        equip_armor(TARMOR"ruby_ring");
}

int stop_attack()
{
	object husband, *tmp;

	husband = present( "hsin", environment() );
	if( !husband ) return 0;
	tell_room( environment(), 
		"����ȵ�: ��С�ӣ����۸������ţ�������\n"
	 );
   tmp =query_temp("protectors");
   if(! tmp || member_array(this_player(),tmp)==-1);
    husband->kill_ob(this_player());
 
}
int kick()
{
   object victim;
   string name,c_name;
   if (!(victim= query_attacker())) return 0;
   if ( (string)victim->query("gender") == "female" ) return 0;
   name =victim->query("name");
   c_name =victim->query("c_name");
   if(random(5)<1) {
   tell_room(environment(this_object()),
   "\n�������: ����֪��Ů�˵�������ȹ�׷ɳ�һ��ֱ��"+c_name+"Ҫ����ʹ��\nʹ     ��     ��     ��\n\n"
);
   victim->receive_special_damage("evil",10);
   victim->block_attack(2);
   return 1;
}
}
void ask_meat()
{
if (!(this_player()->query_temp("fat_quest/meat")) || (int)this_player()->query_temp("fat_quest/meat")==0)
write(
"������װͰ͵�˵��: ʲ����? ������?\n");
else 
{
write(
"�����Ц�����˵: ��Ҷ�����֣�Ϊʲ��ֵ껹���ҵ�ɽ�������ɺóԵ�����\n"
"���������˴�˵������������������......:) \n"
"�ܾ���ǰ���ǵ�ȷ���ù����⣬���Դ���ɽկ�ڿ�ҵ���ᣬ����Ҳû���ù���\n"
"���������õ��⣬��������ȥ�Ĺ������ϵĴ�ɭ�ִ������ģ�������Ϊ��ר��\n"
"�����ɱ��ͱȽϹ�һ���ϣ���Ҫ��Ҫ�Կ�����\n\n"
"���룬��Ȼ�ɱ��ȽϹ��ƺ���̫�ʺϷʶ����ֹ�Ӫ��ҵ...�����㻹����Ϊ����\n"
"������(consider meat)һ�±ȽϺ�\n");
this_player()->set_temp("fat_quest/meat",2);
}
return 0;
}