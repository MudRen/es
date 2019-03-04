#include <mudlib.h>
#include <conditions.h>

inherit OBJECT;

void create()
{
	set_name( "poison pouch", "��ҩ��" );
	add( "id", ({ "pouch", "poison" }) );
	set_short( "��ҩ��" );
	set_long(
		"����һ����ҩ�ۣ������Ҫʹ�������ҩ���� poison <ĳ��>��\n" );
	set( "weight", 20 );
	set( "value", ({ 300, "silver" }) );
}

void init()
{
	add_action( "do_poison", "poison" );
}

int do_poison(string arg)
{
	object dest;

	if( !arg || arg=="" || !(dest = present(arg, environment(this_player()))) )
		return notify_fail("��Ҫ�ö�ҩ��˭��\n");
	if( !living(dest) ) return notify_fail("����������һ������Ҳû��....��\n");
	if ( userp(dest) && (int)dest->query_level()< 5 )
		return notify_fail("�㲻���ݺ��͵ȼ���ҡ�\n");
	call_other( CONDITION_PREFIX"simple_poison", "apply_effect", dest, 10, 20 );
	write(sprintf("��Ѷ�ҩ������%s���ϣ�\n",dest->query("short")));
	tell_object( dest, 
		    sprintf("%s��һ����ҩ�����������ϣ�\n",this_player()->query("c_name")));
	tell_room( environment(this_player()), 
		  sprintf("%s��һ����ҩ������%s���ϣ�\n",
			  this_player()->query("c_name"),
			  dest->query("short")),
		({ this_player(), dest }) );
	if( dest!=this_player() ) {
		dest->kill_ob(this_player());
		this_player()->kill_ob(dest);
	}
	remove();
	return 1;
}
