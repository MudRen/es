#include "../hawk.h"
inherit MONSTER;
int thank;
void create()
{
        ::create();
        set_level(12);
        set_name( "smith","����������" );
        add("id",({"smith"}) );
        set_short( "����������" );
        set_long(@LONG
һ���Źֵ���ͷ������������̹����ܾ��ˣ����ϱ���Ѭ�ĺ�����ģ�ǿ׳��
������Ҳ�ǳ���Ĺ��������������ġ�
LONG
        );
        set( "inquiry", ([
                "god": "@@story",
                "armor" : "@@god_armor"]));
        set( "alignment", 100 );
        set( "gender","male" );
        set( "race","dwarf" );
        set_natural_armor( 30, 22 );
        set_natural_weapon( 25 , 13 , 17 );
        set( "wealth/silver", 20 );
}

void init()
{
        add_action("to_thank","bow");
}

int story()
{
        tell_object(this_player(),@LONG
    ������������������������������������ܿ��������������а취֪
���أ���������������������ǵ����������Ҳ�а취Ϊ�������һ��ǰ��
δ��������װ��(armor)��
LONG
        );
        return 1;
}

int god_armor()
{
        if ((this_player()->query_temp("smore_armor/arcold") == 1)
         && (this_player()->query_temp("smore_armor/elder") == 1)
         && (this_player()->query_temp("smore_armor/las") == 1)
         && (this_player()->query_temp("smore_armor/knight") == 1)
         && (this_player()->query_temp("smore_armor/minister") == 1))
        {
           if (
                (!present("zeus amulet",this_object()))
              ||(!present("spark leggings",this_object()))
              ||(!present("diamond ring",this_object()))
              ||(!present("hades veil",this_object()))
              ||(!present("jupiter armband",this_object()) )
              )
                {
                        tell_object(this_player(),@LONG
�������������˵���㲻���Ҳ��������а취����ö�����....��....
LONG
                        );
                        return 1;
                }
                else
                {
                        tell_object(this_player(),@LONG
������̧��ͷ�������㣬�૵�˵��
���ˣ�����Ҳ�����������˽��������־��ʱ����....��
����������һ������������ϣ�һ�󶣶�����������Խ��Խ���ȣ�ֻ����
����Խ��Խ�죬������ĺ�ˮ�糱ˮ��ӿ��....���ܲ��˸��ȶ��ε��ˡ�
LONG
                        );
                        this_player()->set_temp("block_command",1);
                        call_out("finish",10,this_player() );
                        return 1;
        }
                }
        else
                {
                        tell_object(this_player(),"�������������㡣\n");
                        return 1;
                }
        return 1;
}

int finish()
{
        tell_object(this_player(),@LONG

���������������ã��������˹�����������������������һϮ�������׵Ķ���
����������ս��������㣬��Ҳ˵�������ǿ��ס����ƣ�����ʲ�ᡣ��ֻ֪��
������������ɫ��ӵķ���һ�������˼䷲������ӵ�еģ��������������
���֮�������˼䣬��˵�е���սʿ��
LONG
        );
        this_player()->set_temp("block_command",0);
        call_out("finish2",5,this_player() );
        return 1;
}

int finish2()
{
        tell_object(this_player(),@LONG
�������˰��죬�����������������Ҳ��ûϷ�����������Ҫ�ú�"��л"��һ
�£������ϰѶ��������㡣
LONG
        );
        this_player()->set_temp("thank_smith",1);
        return 1;
}

int to_thank(string str)
{
        object obj;
        if (str != "smith" || this_player()->query_temp("thank_smith") != 1)
                return 0;
        tell_object(this_player(),@LONG
������ع��ؾ���������������Ҿ����������춻��ǰ�������������
�ޡ��������㡣
LONG
        );
        obj = new(ARMOR"gift");
        obj -> move(this_object() );
        command("give gift to " + this_player()->query("name") );
        return 1;
}

