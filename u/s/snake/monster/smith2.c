#include <mudlib.h>

inherit MONSTER;

void create()
{
        ::create();
        set_level( 3 );
        set_name( "smith", "����" );
        set_short( "������" );
        set( "gender", "male" );
        set( "race", "dwarf" );
        set_natural_weapon( 4, 2, 2 );
        set_natural_armor( 30, 10 );
}


int accept_item(object who,object item)
{
     tell_room( environment(), 
            sprintf("��������%s(%s)��ͷ΢Ц��˵��: лл��\n",
                who->query("c_name"),who->query("name") )
                ,who );
        tell_object( who,"�����������ͷ΢Ц��˵��: лл��\n");
                tell_object( who, 
                        "[������� Smith ���񣬵õ� 1000 �㾭��]\n"
                        );
                who->gain_experience(10000);
                }


