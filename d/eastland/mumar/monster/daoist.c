#include <../mumar.h>
inherit MONSTER;
 
void create()
{
        ::create();
        seteuid( getuid() );
        set_level(5);
        set_name( "daoist", "��ʿ" );
        set_short( "��ʿ" );
        add( "id", ({ "groom" }) );
        set_long( "һ����ò���졢�ж����صĵ�ʿ��ȫ��մ���˲�м��\n" );
        set( "gender", "male" );
        set( "natural_armor_class", 26 );
        set( "natural_defense_bonus", 12 );
        set( "no_attack",1 );
        set_natural_weapon(11,4,14);
        set( "chat_chance", 25 );
        set( "chat_output", ({
                "��ʿ���������: ����������Ҳ�ᱻ����...\n",
                "��ʿ̧ͷ���������˵��: ���������������(ghost)���찡...\n",
        }) );
        set( "inquiry", ([
        "ghost" : "@@ask_ghost" ]) );
}
 
int ask_ghost()
{ object obj;
if ( this_player()->query_temp("under") >=2 ) {
tell_object(this_player(),
@ASK
 
��ʿָ������ص��Ͽն���˵��: �������������������ɫ������, ����û��
��˳����ʿ��ָ��ȥ, �ƺ���Ŀ�����������̵��������������ð��......
��ʿ˵��: ��ҹ������, ����������ֵ�Ӧ��һͷ�ޡ�ǧ�������, �����ڴ�
���������������ص�, ��ȻΪ��......����Ҳ��ý��ձ��и��ǳ���, Ҳ����
�������������Ǿ�Ӧ���������ˡ�
��ʿ������ȡ��һ֧���ӡ�
��ʿ˵��: ��ֻ����׷�궤���Խ���������Ԫ�����, ���Ͳ����ٺ�����, ��
          ��Ҫ�պð�......ƶ������Ҫ������, ����Ͱ�������......
 
ASK );
this_player()->set_temp("under",3);
obj=new(OBJS"nail");
obj->move(this_object());
command("give nail to "+lower_case((string)this_player()->query("name")));
tell_object(this_player(),
@ASK
 
��ʿת�˸�����ʧ�ڲݴ�֮�С�
ASK );
}
else {tell_object(this_player(),
@ASK
 
��ʿ˵��: ʲ�ᶼ�������˲�Ҫ����˯��......
 
��ʿ��һ˵���ת����ʧ�ڲݴ�֮��......
ASK
); }
this_object()->remove();
return 1;
}
