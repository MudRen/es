#include <mudlib.h>
inherit OBJECT;
void create()
{
        set_name("book", "Ʈ��ʫ��");
        add( "id", ({ "poet book","p_book" }) );
        set_short( "Ʈ��ʫ��" );
        set("long","�Ȿʫ����ĳʫ�˵���Ѫ�ᾧ����֪��Ϊɶ�������\n");
        set( "weight", 40 );
        set( "unit", "��" );
}

void init()
{
        add_action("to_read","read");
}

int to_read(string s)
{
        if (s != "book") return 0;
        tell_object(this_player(),
                "�㷭���Ȿ�飬��Ȼ����������д����������....������ֻ"+
                "���ö�������....\n\n"+
                "Ӣ���Թ�˭��ʺ��˭�ܴ�㲻��ֽ��\n�����㲻��ֽ��"+
                "�ѵ��㶼����ָ��\n\n....�㿴�����ᣬ���������Լ�����ָ"+
                "......��....\n");
        return 1;
}
