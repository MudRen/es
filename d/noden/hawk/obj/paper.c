
#include <mudlib.h>

inherit OBJECT;
void create()
{
        set_name("paper", "СֽƬ");
	add( "id", ({ "smore_paper","paper" }) );
        set_short( "СֽƬ" );
        set("long","����ֽ����ˮ��ܾ��ˣ��������ֽ��ʪ���ģ��������������֡�\n");
        set( "weight", 10 );
        set( "unit", "��" );
}

void init()
{
        add_action("to_stare","stare");
}

int to_stare(string s)
{
        if (s != "paper") return 0;
        if ((s == "paper") && (this_player()->query_temp("drink_water")==3))
        {
                tell_object(this_player(),
                        "����ϸ�ؿ������ų�ʪ��ֽƬ�����ϽǵĲ�������ԼԼ��"+
                        "д�˼����֣�\n����....����..���ڱ�....��....��..��.."+
                        "......\n    ���˰����㻹�ǲ�֪����дЩɶ....�����"+
                        "ֽ��Ǭ�ٿ����Ǹ�������....��\n");
                return 1;
        }
        if ((s == "paper") && (this_player()->query_temp("drink_water") <3))
        {
                 tell_object(this_player(),
                     "����ϸ�Ŀ������ų�ʪ��ֽƬ��ɶ�������������������"+
                     "����ԼԼ�Ŀ���һ��\nŮ�˵�������������������Ц����\n");
                 return 1;
        }
}
