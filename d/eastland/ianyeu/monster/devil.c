#include <mudlib.h>

inherit MONSTER;

void create()
{
	::create();
   set_level(11);
   set_name( "sexual Devil", "�����ħ" );
   add( "id", ({ "devil" }) );
   set_short( "�����ħ" );
	set_long(
           "�����Ƕ�����½�ж�������, �������ʹ���������ħ��\n"
           "���ö�˵, ��ֻҪ��ƴ������������!\n"
	);
   set_perm_stat( "str", 12 );
   set_perm_stat( "int", 15 );
   set_perm_stat( "dex", 15 );
   set_perm_stat( "kar", 15 );
	set_skill( "dodge", 100 );
	set( "killer", 1 );
   set( "race", "daemon" );
	set( "gender", "male" );
	set( "alignment", -1000 );
	set( "natural_armor_class", 40 );
   set( "natural_defense_bonus", 15 );
   set( "natural_weapon_class1", 20 );
   set( "natural_min_damage1", 10 );
   set( "natural_max_damage1", 15 );
	set( "tactic_func", "my_tactic" );
	set( "chat_chance", 10 );
	set( "att_chat_output", ({
        "�����ħ����¶��а���Ц�ݡ�\n",
        "�����ħ��Ц��: �ٺٺ� .... ���� .... �������㾫����!\n",
	}) );
}

int my_tactic()
{
	object *victim;
	int i;

   if( random(20)<16 || !(victim = query_attackers()) ) return 0;
   tell_room( environment(this_object()),
      "\n�����ħͻȻʩչ����������󷨡���ȥ�㲿�ݵ�Ԫ��!\n\n",
		this_object() );
   for( i=0; i<sizeof(victim); i++ )
		victim[i]->receive_special_damage( "evil", 30 );
	return 1;
}

void die()
{
   object killer;

	killer = query("last_attacker");
   killer->set_temp( "kill_ian_devil", 1 );
   tell_room( environment(this_object()),
     "�����ħ����: �� .... �� .... �һ�Ҫ������Ů!\n" );
   tell_object( killer,
    "\nԭ���������ħ�������������, ���һ�ɱ���Լ���Ů��! ����\n"
      "�˼�һ�󱯾�! �����������п�, ������Ƿ�Ӧ��֪(inform)\n"
      "�����ϡ�\n\n" );
   ::die(1);
}
