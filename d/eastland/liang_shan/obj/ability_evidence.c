#include <mudlib.h>

inherit OBJECT;

void create()
{
	set_name( "evidence of ability", "����֤����" );
	add( "id", ({ "evidence" }) );
	set_short( "evdence of ability", "����֤����" );
	set_long(
		".\n",
		"һ���̽�ĺ�Ư����ֽ������д��һЩ�֣�����\�����\n"
		"����������дЩʲ�ᡣ\n"
	);
	set( "unit", "��" );
	set( "weight", 10 );
	set( "value", ({ 10, "silver" }) );
	set( "no_sale", 1 );
}
void init()
{
//      set("owner",environment(this_object()));
        add_action( "do_read", "read");
}

int do_read(string str)
{
     object owner;
     owner = query("owner");
     if (!str || str != "evidence" )
     return notify_fail(
          "��ʲ��?\n");
          tell_object( this_player(),"[1;33m�����ú������С��д��:   \n" 
          "��֤��"+owner->query("c_name")+"�����Ѵ����ɽ���ص����Ա�׼��\n"
          "��׼��μ���ɽɽ�����С�\n\n"
          "��֤��: �����ʦ����[0m \n");
          return 1;
}
