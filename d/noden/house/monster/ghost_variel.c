#include <mudlib.h>

inherit MONSTER;

void create()
{
	::create();
	set_level(5);
	set_name( "Ghost of Variel", "ޱ����Ĺ��" );
	add( "id", ({ "ghost", "variel" }) );
	set_short( "ޱ����Ĺ��" );
	set_long(
		"�㿴��һ�����˵�Ů�ˣ���������ʮ�������������������������Ӱ��\n"
		"�Զ϶���ֻ�Ǹ���ꡣ\n"
	);
   set( "race", "undead" );
	set( "gender", "female" );
	set( "alignment", 500 );
	set_perm_stat( "int", 10 );
	set_perm_stat( "dex", 10 );
	set_skill( "dodge", 30 );
	set( "natural_armor_class", 20 );
	set( "natural_weapon_class1", 6 );
	set( "natural_min_damage1", 4 );
	set( "natural_max_damage1", 5 );
	set( "tactic_func", "my_tactic" );
	set( "unbleeding",1);
	set( "alt_corpse", "NONE" );
	set_c_verbs( ({"%s����ץ��%s"}) );
	set( "block_aim", ({ "vascular", "ganglion" }) );
	set( "chat_chance", 10 );
	set( "chat_output", ({
		"ޱ����Ĺ��˵��: ������(bury)�ҿ����ĺ��� ....\n",
		"ޱ����Ĺ�걯�˵�̾����\n",
		"ޱ����Ĺ��˵��: �ҵĺ���(son)���޹��� ....\n"
	}) );
	set( "inquiry", ([
		"son" :"�ҵĺ��Ӳ��Ƕ�ħ(devil)���Ұ��ҵĺ��� ...." ,
		"bury" : "����ҵĺ��ӴӶ�ħ���оȳ���������Ĺ԰����Ҽ����ɷ�һ�� ...." ,
		"devil" : "��ħ�������޷�����ģ�������ҵ����ŷ���(incantation) ...." ,
		"incantation" :"���Ǵ�ǰ�Ǹ������˸����ɷ����ħ�� ...." 
	]) );
}

int my_tactic()
{
	object *victim;
	int i;

	if( !(victim = query_attackers() ) || random(20)>5 ) return 0;
	tell_room( environment(this_object()), 
		"����Ӱ�ӱ��ģ����Ȼ���������������Ķ��ߴ���....\n" ,
		this_object() );
	for( i=0; i<sizeof(victim); i++ )
		victim[i]->receive_special_damage( "mental", 15 );
	return 1;
}

void die()
{
	tell_room( environment(this_object()), 
		query("c_cap_name") + "��Ӱ�ӻ���һ�ɰ��̣���ʧ�� ....\n",
		this_object() );
	::die(1);
}

// This function is called when the quest finished
void quest_finished(object player)
{
	tell_room( environment(player), 
		"ޱ����Ĺ��΢Ц��˵��: �ǳ�лл�㣬"+player->query("c_cap_name")+"��\n",
		this_object() );
	die();
}
