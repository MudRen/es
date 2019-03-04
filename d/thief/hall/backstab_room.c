#include <mudlib.h>
#define BACKSTAB_ROOM1 "/d/thief/hall/backstab_room"
#define BACKSTAB_ROOM2 "/d/thief/hall/backstab_room2"
#define TIME_LIMIT 600
inherit ROOM;

void new_mob(object trainee);

void create()
{
	::create();
	set_short( "���̲�����");
	set_long(	@C_LONG_DESCRIPTION
������С͵���������ѵ���ҡ�ר�Ÿ�ϣ����������������С͵��������
�õģ�������˱�����һ���Ӱ�����⣬�ƺ�û���������ڣ��������ߵ�ǽ��
�������һ���ʾ(sign)��Ӧ����һЩ˵���� !! ������ȿ�����
C_LONG_DESCRIPTION
	);

	set( "light", 1 );
	set("c_item_desc",([
		"sign" : @SIGN
��ʾ��д�� :
    �����Ǳ��̲����ң��㽫Ҫ���ܲ��飬�ڱ�������һ�������������㣬
������þ����ַ���ȥȡ�������ϵ�Կ�ף�Ȼ����ܴ���ߵ��Żص���
�ᣬ���������ʱ�����ƣ�С��Ӧ����ѧ���ĸ��ּ��ɣ�Ҳ��Ҫ��������С
����������ϣ������˳������ !!
 
    ���㳢�Դ��صĹ��̣�ʧ�ܵ�״�������� :
    
    1. ���������˶��� 	: ��Ķ��ֶ��ǹ����ǰ����װ�ģ�������
			  �зִ磬ֻ������"����", �����������ʧ��, 
			  ���Լ�С�ġ�
    2. ʱ���þ�		: ʱ����̫���ˣ����ַ��ˣ������ϳ������ң���
			  ����εĲ���ѾͰ׽��ˡ�
    3. ��������		: ������ʱ�� quit ����Ϊ����ʧ�ܡ�
	
    ���⣬�����᲻�۳ɰܣ���ǵ���̩��˹Ҫ�����װ��(equip)��

SIGN
	]) );
	set( "exits", ([ 
		"north" : BACKSTAB_ROOM2 ]) );
	set("pre_exit_func",([ "north" : "to_north" ]) );
	reset();
}

int to_north()
{
	object *invs;
	int i;
	if ( !query("begin_test") ) {
		invs = all_inventory(find_object_or_load(BACKSTAB_ROOM2));
		for ( i = sizeof(invs)-1 ; i >=0 ; i-- )
			if ( !userp(invs[i]) ) invs[i]->remove();

		new_mob(this_player());
		set("begin_test",time()+TIME_LIMIT );
		if ((object)query("tester") == this_player())
			this_player()->set_temp("skip_dead",1);
	}
	return 0;
}

void new_mob(object trainee)
{
	object mob;
	int lv,bs_lv;
	lv = (int)trainee->query_level();
	bs_lv = (int)trainee->query("thief_level/backstab");
	mob = new("/d/thief/hall/monsters/bs_mob");
	mob->set_level(lv);
	mob->set_natural_weapon(lv*3/2,lv,lv*12/10);
	mob->set_perm_stat("karma",lv/2);

	mob->set("hit_points",10+3*bs_lv);
	mob->set("max_hp",10+3*bs_lv);
	mob->move(BACKSTAB_ROOM2);
}

int fail_to_pass(object me)
{
	delete("begin_test");
	delete("tester");
	set("using",0);
	tell_object(me,"\nһ������˵�� : �㻨̫��ʱ���� !! �´����԰� !!\n\n"); 
	me->delete_temp("skip_dead");
	me->move_player("/d/thief/hall/thief_guild","SNEAK");
	return 1;
}

int do_quit()
{
	tell_object(this_object(),
		"һ������˵�� : ������? �ð�, �´������Կ����ܱȽϺá�\n");
	delete("begin_test");
	delete("tester");
	set("using",0);
	return 0;
}

do_auc()
{
	tell_object(this_object(),"�㲻����������н��� !!\n");
	return 1;
}

void init()
{
	int timer ;

	add_action("do_auc","auction");
	add_action("do_quit","quit");

	timer = query("begin_test") ;
	if ( ! timer ) {
		set("using",1);
		set("tester",this_player());
		return ;
	}
	if ( 
		(time() > timer) && 
		((object)this_object()->query("tester") == this_player())) {
		fail_to_pass(this_player());
	}
		return ;
}
