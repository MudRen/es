#include "../mad.h"

inherit MONSTER;

void create()
{
	::create();
	set_level(5);
   set_name( "raccoon dog", "Ұ��" );
   add( "id", ({ "dog", "raccoon" }) );
   set_short( "Ұ��" );
   set_long( "���Ƕ�����½�����ز��Ķ���, ��˵����ʩ�估����\n" );
   set( "race", "beast" );
   set( "gender", "male" );
	set("unit","ֻ");
	set_perm_stat( "dex", 10 );
   set( "alt_corpse", IANMOB"satyr" );
	set_c_verbs( ({ "%s������ҧ��%s", "%s��ǰצ��%sץ��" }) );
	set_c_limbs( ({ "ͷ��", "����", "�Ų�","β��" }) );
}

void die()
{
        tell_room( environment(this_object()), 
          "\nҰ����������, ��֧����........\n\n"
          "����������ȥʱ............\n\n"
          "ͻȻҰ���ӵ���׽��һƬ��Ҷ����ͷ��..........\n\n"
          "��һ����շ�֮��......Ұ�������һ����ǿ����ɫ��!!\n\n"
          , this_object() );
        ::die(1);
}
