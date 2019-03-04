#include <mudlib.h>
#define MASK_OBJ "/d/thief/hall/misc/mask"
#define MAKE_SKILL "anatomlogy"
inherit OBJECT;

init()
{
	add_action("do_cut","cut");
}

void create()
{
	seteuid(getuid());
	set_name( "knife","��ƤС��" );
	set_short( "��ƤС��" );
	set_long( @LONG
    ����һ���ᱡ������С��, ���ó�������ߵ��˳��õĹ���֮һ��
������� cut skin from corpse ȡһ��Ƥ������ߡ�
LONG
	);
	set( "weight",10 );
	set( "unit","��");
	set( "value",({ 230,"silver" }));
}
int check_skill(object me)
{
	int skill1,skill2,rate;
	if ( (string) me->query("class") != "thief" ) 
		return 0;
	if ( ( skill1 = (int) me->query_skill(MAKE_SKILL) ) == 0 )
		return 0;
	if (random(skill1 + (int) me->query_stat("piety") ) > 20 )
		return 1;
	else 
		return 0;
}

int query_sp_cost(object me)
{
	return ( 80 - (int)me->query_skill(MAKE_SKILL) ) ;
}

do_cut(string arg)
{
	string *args,tmp;
	int sz,i,skill;
	object *inv,env,mask,corpse,mob;

	if ( ! arg ) 
		return notify_fail("����Ҫ��ʲ��?\n");
	if ( sscanf(arg,"skin from %s",tmp) != 1)
		return 0;
	if ( !this_player()->query_vision() )
		return notify_fail("����һƬ��� ! ��ʲ��Ҳ������ !!\n");
	env = environment(this_player());
	if ( ! (corpse = present(tmp,env)) ) 
		return notify_fail("����û�����֡��� ��\n");
	if (sscanf((string)corpse->query("short"),"%s��ʬ��",tmp) < 1 || tmp == "����") {
		return notify_fail("������Ѿ�������, ������߿��ܻ��Ƥ����, �����?? \n");
	}
	if ( (i = query_sp_cost(this_player())) > (int)this_player()->query("spell_points") ) {
		return notify_fail("�㾫����̫����, �޷������־�ϸ�Ĺ�����\n");
	}

	this_player()->add("spell_points",-i);
	if ( ! (tmp = (string) corpse->query("npc")) ) 
		return notify_fail("����Ƥ��,��������ֲ��ϲ����ʺ�����ߡ�\n");
	mob = new(tmp);
	if ( nullp(mob) ) {
		write("����� bug, ��֪ͨ��ʦ!\n");
		return 1;
	}

	if ( check_skill(this_player()) ) {
		tell_room(env,sprintf("%s�ڡ����ϻ�����, ȡ��ĳ��������\n",this_player()->query("c_name") ), this_player() );
		write(sprintf("��С�������Ĵӡ�����ȡ����Ƥ, ˳���������%s����ߡ�\n",(string)mob->query("c_name") ));
		mask = new(MASK_OBJ);	
		mask->set_short(mob->query("short")+"�����");
		mask->set("mask_name", mob->query("name") );
		mask->set("c_mask_name",mob->query("short") );
		mask->add("extra_ids",mob->query("id"));
		mask->move(this_player());
		corpse->remove();
		mob->remove();
		return 1;
	} else {
	tell_room(env,sprintf("%s�����ӡ�����ȡ����Ƥ, ���ʧ����!\n",this_player()->query("c_name") ), this_player() );
		corpse->remove();
		mob->remove();
		return notify_fail("��һ����С��, ���Ƥ, ��������!!\n");
	}
}
