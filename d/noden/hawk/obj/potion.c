
#include <mudlib.h>

inherit OBJECT;
void create()
{
        set_name("potion", "��ֵ�ҩˮ");
        add( "id", ({ "s_potion","potion","strange potion" }) );
        set_short( "��ֵ�ҩˮ" );
        set("long",@LONG
����һ������ֵ�ҩˮƿ������װ��Щ��ɫ��ҩˮ�����滹�����ű�ǩ(list)��
LONG
        );
        set( "weight", 20 );
        set( "unit", "ƿ" );
}

void init()
{
        add_action("to_read","read");
}

int to_read(string s)
{
        if (s != "list") return 0;
        tell_object(this_player(),@LONG

����ϸ�Ŀ�ʼ��������д�ı�ǩ��
        �ɷݣ������޻��ĸ�����������Ҷ�ݣ�ͩľ����
        ���ã�ǿ�����⼰�񾭷�Ӧ��
��С���ղأ������⴫��
LONG
        );
        return 1;
}
