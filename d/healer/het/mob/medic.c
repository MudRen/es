#include <mudlib.h>
#include <conditions.h>
#include "../wang.h"
inherit MONSTER;
inherit TEACHER;

void create()
{
	object ob1;
	::create();
	set_level(19);
	set_name( "Medic Wang", "��ҩʦ" );
	add( "id", ({ "medic", "wang" }) );
	set_short("��ҩʦ" );
	set_long(
@LONG
��ҩʦԭ������ҽ�߹����һԱ��������ҽ�߹��ϵĲ�ҩȨ��������������
��ҩ�������ĵص㶼�������ֵġ�����ǰͻȻ�뿪���ᣬ������ط����ӡ�
����ÿ�첻�ǳ�ȥ��ҩ���ǵ��Ƹ�����ֵ�ҩ��û����֪��������ʲ�ᡣ
LONG
	);
	set( "race", "human" );
	set( "gender", "male" );
	set_perm_stat("str",30);
	set_perm_stat( "int", 30 );
	set_perm_stat( "kar", 25 );
	set_perm_stat( "dex", 30 );
	set_skill( "dodge", 100 );
	set_skill( "blunt", 100 );
	set_skill( "anatomlogy", 100 );
	set( "aiming_loc", "weakest" );
	set( "max_hp", 600 );
	set( "force_point", 100 );
	set( "hit_points", 600 );
	set_natural_armor( 100, 50 );
	set_natural_weapon( 30, 15, 25 );
	set( "special_defense", ([ "all": 50,"none":60]) );
	set( "aim_difficulty",([ "weakest":30,"vascular":20 ]) );
	set( "alignment", 500 );
        set( "inquiry", ([
		"poison" : "@@ask_poison",
		"herb" : "@@ask_poison",
		"train" : "@@ask_train",
		])
	);	
        set( "chat_chance", 2 );
        set( "chat_output", ({
                "��ҩʦ�૵�����:���޸�ˮ����.. ������Ǯ... ��\n",
                "��ҩʦվ����, �߳�����, ��һ�������Щҩ�ݽ�������ʼ���䡣\n",
        }) );

	set_lessons( ([
		"venomlogy" : ({ 150,90 })
	]));

	set( "tactic_func", "my_tactic" );
	wield_weapon( MY_WEAPON );
	equip_armor( ITEM"deer_gloves.c" );
	ob1 = new(ITEM"box.c");
	ob1->move(this_object());

}

void init()
{
	teacher::init();
}

//
// msgs[random(sizeof(msgs))]
// but ��γ����� call when fighting , ����������� size ���ȽϺ�
//
int my_tactic()
{
	string *msgs = ({"\n��ҩʦ��ҩ����ץ��һ�Ѷ�ɳ����%s��ȥ!\n\n",
			 "\n��ҩʦ�������һ����ɫ��ˮ�����%s������!\n\n",
			 "\n��ҩʦ��ָ����ͻȻ����һ����ɫ���̣�ֱ��%s...\n\n",
			 ""});
	string msg1 = "��ҩʦ������Ц˵�������������ö�������ǰ��Ū���㲻֪����а���Ū����?��\n ��ҩʦȡ��ҩ����£������нⶾ�ˡ�\n"; 
	object me,victim,env;
	int type;
	string msg;

	me = this_object();
	env = environment( me );
	if ( me->query("conditions/weak") ) {
		tell_room(env,msg1);
        	me->modify_stat("str",(int) me->query("weak"));
        	(CONDITION_PREFIX + "weak")->remove_effect(me);
	}
	if ( me->query("conditions/slow") ) {
		tell_room(env,msg1);
        	me->modify_stat("dex",(int) me->query("slow"));
        	(CONDITION_PREFIX + "weak")->remove_effect(me);
	}

	if ( ( me->query("conditions/simple_poison")) ) {
		tell_room(env,msg1);
		(CONDITION_PREFIX + "simple_poison")->remove_effect(me);
	}

//      ����

	victim = query_attacker();
	if ( random( 10 + victim->query_perm_stat("kar") ) > 14 )
		return 0;

	msg = sprintf( msgs[ (type = random(3)) ], victim->query("c_name") );
	tell_object(victim,
              "\n��ҩʦ˫��һ�ӣ���Ц�� �� ������ !! ���ú� !! ��������������ҩ !!�� \n" );
	tell_room(env,msg,victim);
	switch(type) {
		case 0:
        		(CONDITION_PREFIX + "simple_poison") ->
                		apply_effect(victim,12,6);
			break;
		case 1:
        		(CONDITION_PREFIX + "weak") ->
                		apply_effect(victim,12,6);
			break;
		case 2:
        		(CONDITION_PREFIX + "slow") ->
                		apply_effect(victim,12,6);
			break;
		default:
			break;
	}
	return 0;	
}

void ask_poison(object visitor)
{

	if( (string) visitor->query("class") != "healer" ) {
	 	tell_object(visitor,"�㲻��ҽ�����������ǲ�����ҩ�Ե��ˣ��������˰�\n") ;

	}  else {
		     tell_object(visitor,
"��Ϥ��ҩ����һ���ǻ��£�����öԵط�..�����뿪��ҽ�߹���һ��ʱ����,\n"
"��һ��ʱ���ڣ��Ѽ���һЩ�䷽�����⻹���Լ����ֵġ�\n"
"���������Ȥ���ҿ��Խ��㶾��ѧ������¶��ļ��ɲ����ã����Լ��п����ж��ġ�\n"
"ҩ�������淿�䣬��ȥ�����ɡ�\n"
			);
	}
}

void ask_train(object who)
{
	if ( (string) who->query("class") == "healer" ) {
		tell_object( who ,
"�����ѧ����ѧ(venomlogy)��? ���Ҷ����ˡ�������ȱЩ�ⶾ�õ�ҩ�ģ�\n"
"������ܴ�һЩ����,�Һ��������ġ�\n");
	} else
		tell_object( who,
"�ܱ�Ǹ, ��ֻ����ҽ��, ����������ɡ�\n");
		
}

// not finished ..
int check_trainee(object trainee)
{
	if ( (string) trainee->query("class") != "healer" ) {
		tell_object(trainee,"�ܱ�Ǹ, �������ֻ���ڸ���ҽ�ߡ�\n");
		return 0;
	}
	if (! (trainee->query_temp("give_herb/herb1")  && 
	     trainee->query_temp("give_herb/herb2")) ) {
		tell_object(trainee,"��������Щҩ�ĸ��Ұɡ�\n") ;
		return 0;
	}
	return 1;
}

int accept_item(object who, object item)
{
	if ( (string) item->query("ident") == "SWAMP_BERRY" ) {
		tell_object( who, "лл�㣬������Ҫ��ζҩ�ġ�\n") ;
		who->set_temp("give_herb/herb1",1);
		item->remove();
	} else if ( (string) item->query("ident") == "SWAMP_MOSS") {
		tell_object( who, "лл�㣬������Ҫ��ζҩ�ġ�\n") ;
		who->set_temp("give_herb/herb2",1);
		item->remove();
	} else if ( item->query("ident") ) {
		tell_object( who,"��Ȼ�Ҳ���Ҫ��ζҩ, ����лл�㡣\n");
		item->remove();
	}
	return 1;
}

void die()
{
	object killer,env,*inv;
	int i;
	env = environment( this_object() );
        inv = all_inventory( env );
	killer = query("last_attacker");
	if ( ! killer || ! env || !inv ) {
		::die();
		return;
	}

        i = sizeof(inv);
	tell_room(env,"��ҩʦ˵��:����.. ���ǻ���ڵ�....��\n",this_object());
        while(i--) {
		if ( living(inv[i]) && ! inv[i]->query("npc") )
                	inv[i]->set_temp("kill_wang",1);
        }
     	::die();
}

