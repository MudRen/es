#include <mudlib.h>
#define BACKSTAB_ROOM1 "/d/thief/hall/backstab_room"
#define TRAIN_ROOM "/d/thief/hall/thief_trainroom"

inherit MONSTER;
void create()
{
	::create() ;
	seteuid(getuid()) ;
	set_level(19);
	set_name("maskman", "������");
	set_short( "������");
	set_long( @LONG
����������β��Ե������٣�Ҳ���������ǰ����ƽʱҲ����һ�������ƨ��
��������������һ��û�б����С����ߣ�����������۾�����ض����㣬��
������Ѱ��������㡣

	"���κη��������Ұ� !! " ���������ݷ�ӵص״��� ...

LONG
	);
	set_skill( "dodge", 80 );
	set("gender","male");
	set( "race", "human" );
	set("exp_reward",1);
	set("unbleeding",1);
	set("aim_difficulty",
		([ "vascular":35, "ganglion":50 ]) );
	set("tactic_func","my_tactic");
	set("alt_corpse","NONE");
}

int my_tactic()
{
	object killer;
	killer=this_object()->query_attacker();
	if ( ! killer ) 
		return 0;
	if ( ((int) killer->query("hit_points") * 100 / (int) killer->query("max_hp")) < 25 ) {
	this_object()->cease_all_attacks();
	killer->cease_all_atackers();
	tell_object(killer,
		"������������Ц�� : ���� !!�㲻����, ������ !!\n"
		"����������������ͻȻ��ʧ����Ӱ���١�\n");
	    killer->move(TRAIN_ROOM);	
	    BACKSTAB_ROOM1->set("using",0);
	    BACKSTAB_ROOM1->delete("begin_test");
	    BACKSTAB_ROOM1->delete("tester");
	    this_object()->remove();
	}
	return 0;	
}

void die()
{
	object killer ,ob;
	if ( killer = (object)query("last_attacker")) {
	
	killer->set_temp("pass_test",1);
	tell_object(killer,
		"������������Ц�� : ���� !!���Ѿ�֤����������ˣ�\n"
		"����ȥ�� !! ���������ʹ���´μ��� ... �ٺ� ...\n\n"
		"������ͻȻ��ʧ����Ӱ���١�\n");
	}
	::die(1);
}
