#include "../moyada.h"

inherit MONSTER;

int done;

void create ()
{
	object sword;
	
	::create();
	set_level(18);
	set_name( "Wan Fu", "����" );
	add ("id", ({ "boss", "wanfu", "wan fu", "wan", "fu" }) );
	set_short( "�곤����" );
	set_long(@LONG
����������̵���ϰ壬��������ʮ��ǿ׳��ȫ����һ��һ��أ��൱
���ˡ�������һ�������ı��ӣ������������С����к������ˡ��ޣ�������
��Я����һ�Ѵ󵶣����Ͽ���һ����������������
LONG
	);

    set( "alignment", 1500);
    set( "gender", "male" );
    set( "race", "human" );
    set( "unit", "��" );
	set_perm_stat( "dex", 12 );
	set_perm_stat( "str", 25 );
	set_perm_stat( "int", 10 );
	set_perm_stat( "con", 30 );
	set_perm_stat( "piety", 5);
	set_perm_stat( "karma", 20);
	set( "aim_difficulty", ([ "critical" : 50, "weakest" : 30, ]) );
	set( "special_defense",
	   ([ "all" : 20, "none" : 10 ]) );
	set ("max_hp", 1000);
	set ("hit_points", 1000);
	set ("wealth", ([ "gold": 100 ]) );
	set_natural_weapon( 40, 20, 30 );
	set_natural_armor( 85, 45 );
    set ("weight", 900);
    set( "exp_reward", 20000 );
    set( "inquiry", ([
         "job" : "@@ask_job",
         "devil" : "��˵��ħ����αװ��ƽ����, ��Ҫ�������Ʒ�����������Ρ�\n",
    ]) );
    
	set ("chat_chance", 5);
	set ("chat_output", ({
	    "������ë�����������㿪�ĵز������Ĵ󵶡�\n",
	    }) ); 
	set ("att_chat_output", ({
	    "����˵��С�ӣ��㵨��������ս���е���\n",
	    "����˵���㻹���ͽ���? �㲻���ܴ���ҵġ�\n",
	    "����˵���ٸ���һ�λ��ᣬ�㻹��Ͷ����? \n",
	    }) );
	wield_weapon(MOYADA"obj/glaive");
	set("tactic_func", "special_attack");
}

int catch_huntee( object who )
{
    tell_room( environment(this_object()), 
      "�����ܲ�ˬ����"+who->query("c_name")+"˵: �㻹�ҽ�������Ĳ��ͷ��ˣ��Ҿͳ�ȫ�㣬����!\n"
    ,  ({ this_object(), who }) );
    tell_object( who,
      "�����ܲ�ˬ������˵: �㻹�ҽ�������Ĳ��ͷ��ˣ��Ҿͳ�ȫ�㣬����!\n"
    );
    return 1;
}

void ask_job( object who )
{
      if( done )
        tell_object( who,
          "����˵���Բ����������ڲ�ȱ�ˡ�\n");
      else 
        tell_object( who, 
          "����˵���ҵĴ����Ҿ�˵����һֻ��ħ�����˶��������ţ����ܰ��ҳ�������?\n");
}

int member_killer( string a, string *b )
{
    int i;
    if( !b ) return 0;
    for( i=0; i<sizeof(b); i++ )
      if( a == b[i] ) return 1;
    return 0;
}

int hunt_check( object wanfu, object victim )
{
    int i;
    object *attackers;
    string *hunt_list;
    
    hunt_list = wanfu->query("hunt_list");
    attackers = wanfu->query_attackers();
    if( victim && !member_group( victim, attackers ) &&
        member_killer( (string)victim->query("name"), hunt_list ) ) {
      tell_room( environment(wanfu), 
        "������Ц��˵: "+victim->query("c_name")+"������Ϊ quit �����ӳ��ҵ���������? ����!\n"
        , wanfu );
      kill_ob( victim );
      return 1;
    }
    return 0;
}

void relay_message(string class1, string msg)
{
	string who, str;
	object player;

	if( sscanf( msg, "%s(%s)���˹�����", str,who )==2 ) {
		if( !player = find_player(lower_case(who)) ) return;
		if( hunt_check( this_object(), player ) ) return;
		if( !done && ((int)player->query_quest_level("wanfu")) < 1 &&
			player->query_temp("wanfu/done") ) {
			tell_object( player, @THANKS
����˵��лл�㣬������õõı��ꡣ
�������� 50 ö��ң����� 12000 �㾭�顣
   [   �����������������   ] 
THANKS
);

			player->gain_experience(12000);
			player->credit("gold", 50);
			player->finish_quest("wanfu", 1);
			done = 1;
			return;
		}
		tell_room( environment(), 
			"����˵����ӭ���٣���Ҫʲ����\n" );
	} else if( sscanf( msg, "%s��%s���뿪��", who,str )==2 )
		tell_room( environment(), 
			"����˵��лл���٣��´�������\n" );
}

int special_attack()
{// 15% use it! damage 45-55.
    object *victim;
    string *hunt_list, victim_name;
    int i;
    
    if( !query_attacker() ) return 0;
    hunt_list = (string *)this_object()->query("hunt_list");
    victim_name = (string)query_attacker()->query("name");
    if( !hunt_list )
      hunt_list = ({ victim_name });
    else if( !member_killer( victim_name, hunt_list ) )
      hunt_list += ({ victim_name });
    this_object()->set("hunt_list", hunt_list);
    
    if( !(victim = query_attackers()) || (random(20)<3) ) return 0;
    tell_room( environment( this_object() ), 
      "������: ���ҵľ��� ����ն! \n"
      "  ֻ����������һ�������Ĵ󵶰��������������е������¡�\n"
      "һ��ը֮�ᣬ�����ܹ����Ѵ󵶼��˻�ȥ��\n" ,
      this_object()
    );
    i = sizeof(victim);
    while(i--) {
      victim[i]->receive_damage(45+random(10));
      "/d/magic/magic"->report( this_object(), victim[i] );
    }
    return 1;
}

void reset()
{
    done = 0;
}
