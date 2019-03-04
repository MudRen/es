// gate.c: an object for spell 'ASTRAL-GATE'////#pragma save_binary
#include <mudlib.h>

inherit OBJECT;

void	set_destination(object dest);
object	gate_destination;

void	create()
{
	set_name("astral gate", "�ǽ�֮��");
	add( "id", ({ "gate" }) );
	set_short( "�ǽ�֮��" );
	set( "long", "@@query_long");
	set( "weight", 0);
	set( "unit", "��");
	set( "prevent_insert", 1);
	set( "prevent_drop", 1);
	set( "prevent_get", 1);
}

void	init()
{
   add_action( "enter_gate", "enter");
}

void	set_destination( object dest )
{
	gate_destination = dest;
}

int		enter_gate( string s)
{
	if (!s)	return notify_fail( "�������ʲ�ᶫ��?\n" );
	if ( (!present(s)) || (present(s) != this_object()) )	return 0;
// prevent bugs
	if ( (!gate_destination) || (gate_destination->query("no_teleport")) ) 
	{
		tell_room( environment( this_object()), 
			"����Ӵ�����ʱ, �ź�Ȼ���ҵ�ҡ������, ����ǿ�ҵ��������ʧ��\n"
		);
		::remove();
		return 0;
	}
	
	this_player()->move_player( gate_destination,
		this_player()->query("c_name") + "�߽����ǽ�֮��" );
	return 1;
}

int		remove()
{
	tell_room( environment( this_object() ), 
		"���Ž�����תΪ����, ��ʧ�ˡ�\n"
	);
	return ::remove();
}

string	query_long()
{
	string s;
	
	s= "�����е�ҡҡ�λε�, �������ŵı˷���\n";
	if (gate_destination) {
		s = "��͸������, �����ŵ���һ��:\n";
		s = s + gate_destination->query("long");
		return s;
	}
	else return s;
}
