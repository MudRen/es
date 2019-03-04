#include <mudlib.h>
#include <move.h>
inherit OBJECT;

void create()     
{
#include <compress_obj.h>
	set_name( "light ball", "����" );
	set_short( "�������");
	set_long( @LONG
��������ɷ������Ӽ��϶���, ��ɢ���������Ĺ�â, ������Կ������ܵľ��
LONG
    );
	set("id", ({ "ball" }));
	set("unit", "��");
	set("weight", 0);
	set("light", 1);
	set("no_insert", 1);
	set("useless", 1);
	set("prevent_insert",1);
	set("value", ({ 1, "silver" }));
}

void set_fuel(int fuel)
{
    call_out( "burn_out", fuel, this_object() );
}

void burn_out(object obj)
{
	object owner;

	owner = environment(obj);
	if( living(owner) ) {
	  tell_object( owner,"��Ĺ������˼��£���ʧ�ˡ�\n");
	  tell_room( environment( owner ), 
	    owner->query("c_name")+"�Ĺ������˼��£���ʧ�ˡ�\n" ,
	    owner
	  );
	}
    obj->remove();
}

int move( mixed place )
{    
    if( objectp(place) && !living(place) )
      call_out( "disappear", 2, this_object() );
    return ::move(place);
}

void disappear( object obj )
{
    tell_room( environment(obj), 
      "�������˼��£���ʧ�ˡ�\n" , obj
    );
    obj->remove();
}
