#include "../almuhara.h"

inherit OBJECT;

void create()
{
	set_name("note","�̺�");
	set_short("һ��̺�");
	set_long(
		"һ��̺�������д�������֡�\n"
	);
	set("no_sale",1);
	set( "unit", "��");
	set("weight", 2);
	set("value", ({ 5, "silver" }));
}

void init()
{
	add_action("read_note","read");
}

int read_note(string str)
{
    object ob;
    if ( !str || str != "note" ) return 0;
    else {
      ob = environment(this_object());
      if ( ob != this_player() ) 
        return 0;
      else 
        {
          write("лл�㣬��Ե�ˡ�\n"
          	"�����Իر���ֻ������������ӣ����ǽ�����Ĺ�Ĺؼ���\n" );
          return 1;      
        }
    }
}
