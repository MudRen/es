
#include <mudlib.h>

inherit OBJECT;
void create()
{
	seteuid(getuid());
        set_name("pearl", "��ħ��");
        add( "id", ({ "pearl","daemon pearl" }) );
        set_short( "��ħ��" );
        set("long",@LONG
���������¿�����ķķ��������������ı��飬��˵�н���ħ�������������
LONG
        );
        set( "weight", 5 );
        set( "unit", "��" );
}

void init()
{
        add_action("to_say","say");
}

int to_say(string s)
{
        if (s != "ern!-sdl") return 0;

        if ( (this_player()->query_temp("smore_armor/arcold") != 1 )
          || (this_player()->query_temp("smore_armor/elder") != 1)
          || (this_player()->query_temp("smore_armor/knight") != 1)
          || (this_player()->query_temp("smore_armor/minister") != 1)
          || (this_player()->query_temp("smore_armor/las") != 1) )
                return 0;

        tell_object(this_player(),@LONG
�����еı��鷢��һ����â����ʳ���޵����ϡ�

����ԸϿ���ͼȥ����(control)��
LONG
        );
        this_player()->set_temp("control_flesh",1);
	this_object()->remove();
        return 1;
}
