#include <mudlib.h>
#include <conditions.h>

inherit MONSTER;

void create()
{
	::create();
	set_level( 3 );
	set_name( "doctor Wu", "��ҽ��" );
	set_short( "��ҽ��" );
	add("id", ({ "wu","healer", "doctor" }) );
	set_long( @LONG
�㿴��һλ��ĸ��ݡ��۾�ϸС�������ˣ����ҽ����һλ��Ѫ�������ĸ�
����һ�����Զ�����ѧ�ߣ����Ӹ�������ѧ�������йز�ҩ���β���֪ʶ��
����������й�ҽ��(heal)�����飬�����Ƿ��ܸ����������Ҳ���Ը�Ǯ
(pay) �������㿴������״����
LONG
	);
	set( "gender", "male" );
	set( "race", "human" );
	set( "inquiry", ([
		"heal" : "@@ask_heal"
	]) );
}

void init()
{
	::init();
	add_action("do_cure", "pay");
}

void ask_heal( object player )
{
	tell_object( player, 
		"��ҽ��΢Ц��˵: �һ������￪һ��ҽԺ�������´�������\n");
}

int do_cure(string arg)
{
	string who, type;
	int num, *data;

	if( !arg || arg=="" || sscanf( arg, "%s %d %s", who, num, type)!=3 )
		return notify_fail( 
			"��˭������Ǯ��\n");
	if( !id(who ) ) return 0;
	if( type != "silver" ) {
		tell_room( environment(), 
			"��ҽ��˵��: �Բ�����ֻ�����ҡ�\n" ,
			this_object() );
		return 1;
	}
	if( !this_player()->debit(type, num) ) 
	        return notify_fail( "��û����������ҡ�\n");
	if( !data = this_player()->query("conditions/sick") ) {
		write("��ҽ���������µش������㣬˵: ������ܺ�, ��û��������\n");
			return 1;
	}
	if( num < 50 + 10*data[1]*data[2]/data[0] ) {
		write("��ҽ���������µش������㣬ҡһҡͷ����Ǯ�˻����㡣\n");
		this_player()->credit(type, num);
		return 1;
	} else {
		write("����һ����ϸ�ļ�飬��ҽ��Ц��˵: ��Ĳ������ͺ��ˡ�\n");
		write("��ҽ��ȡ��һ����Ͳ, ������ϴ���һ�롣\n");
		SICK->remove_effect(this_player());
	}
	return 1;
}
