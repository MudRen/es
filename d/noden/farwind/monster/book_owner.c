
#include <mudlib.h>

inherit MONSTER;

void create()
{
        ::create();
        set_level( 10 );
        set_name( "book shop owner", "����ϰ�" );
        add( "id", ({ "owner" }) );
        set_short( "the book shop owner", "����ϰ�" );
   set_long( @LONG
�����ϰ���Լ��ʮ, ��������ʱ����־Ҫ��Ϊѧ��, ��ȴ�����
���Ѷ�δ����Ը--����Լ�ʮ��Ļ���˴˼���ꡣ������֪��Ϊ��
ʲ���£��ϰ���������ü�������������ⲻ̫�á�
LONG
        );
        set( "no_attack", 1 );
        set( "gender", "male" );
        set( "inquiry", ([
               "trouble" : @TROUBLE
�����ҵķ��հ�? �����鿴����֪��������Ϊ����! ��....��....
TROUBLE
                ,"help" : @HELP
Ҫ���ҵ�æ? ����æ���������ҵ�����! лл��!
HELP
 ]) );

        set( "chat_chance", 20 );
        set( "chat_output", ({
"����ϰ�˵�� : ��....��......���Ƿ���(trouble)��....�������ư�......\n",
"����ϰ��������� : ��.....�����鶼����������, ����˭������ ? \n"
        }) );

}
