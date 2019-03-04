#include <mudlib.h>

inherit OBJECT;

void create()
{
   seteuid(getuid());
   set_name( "mummy", "ľ����" );
   set_short( "ľ����" );
   set_long(
	"һ��˶���ľ����, �����������������(anatomise)����\n"
	);

   set( "unit", "��" );
   set( "weight", 5000 );
   set( "prevent_get", 1 );
}

void init()
{
   add_action( "am_corpse", "anatomise" );
}

int am_corpse(string str)
{
   object heart, weapon;
   int op_succ, op_fail;

   op_succ = this_player()->query("op_succ_count");
   op_fail = this_player()->query("op_fail_count");

   weapon = (object)this_player()->query("weapon1");

   if( !str || str != "mummy" )
   return notify_fail( "����Ҫ��ɶ?\n" );
   if( !weapon || (string)weapon->query("type") != "dagger" )
   return notify_fail( "���ƺ�ȱ���ʵ��Ľ��ʹ��ߡ�\n" );
   if( op_succ >= op_fail && op_succ +op_fail > 25
     && (string)this_player()->query("class") == "healer" ) {
	heart = new( "/d/noden/tomb/obj/heart" );
	tell_object( this_player(),
	"�����˵صõ�һ�Żƽ�֮��!\n" );
	heart->move(this_player());
   }
     write( "���ľ���������ˡ�\n" );
   tell_room( environment(this_object()),
	  "ľ������"+this_player()->query("c_name")+"�����ˡ�\n", ({ this_player() }) );
   this_object()->remove();
   return 1;
}

