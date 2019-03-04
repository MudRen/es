// mess.c
// This object is created when a healer failed to mix the coorect reagents.
// By Annihilator 09/27/94
#include <mudlib.h>

inherit OBJECT;

void create()
{
	set_name("messed substance", "����");
	add("id", ({ "substance", "mess" }) );
	set_short("some messed substance", "����" );
	set_long(
		"You see some messed substance of green and brown. It smells\n"
		"stink....\n",
		"�㿴��һ�Żƻ����̵����࣬�������йɶ����\n" );
        set( "weight", 1 );
	set( "unit", "��" );
	set( "useless", 1 );
	set( "prevent_insert", 1 );
	call_out("decay", 50);
}

void decay()
{
	// We don't want the messed substance flood your beautiful mud.
	remove();
}
