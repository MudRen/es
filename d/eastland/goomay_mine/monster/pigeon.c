#include <../zeus.h>        
        
inherit MONSTER;

void create ()
{               
       ::create();
       set_level(15);
       set_name( "pigeon", "С����" );
       set_short( "pigeon","С����");
       set("unit","ֻ");
       set_long(@LONG
�㿴��һֻ�ɰ��Ķ�����ڵ���������ʳ��������һ˫�ںڵ�
С�۾��������㣬�޹��ı���������ڶ���˵����Ҫ�˺��ң�
LONG
);
       set_perm_stat("dex", 20);
       set ("weapon_class1", 20);
       set ("tactic_func","my_tactic");
       set ("armor_class", 25);
       set_c_verbs(({"%s�����ļ�����%s��ȥ"}));
       set_c_limbs(({"����","����","�Ų�","ͷ��"}));
}
int my_tactic()
{  object obj;
   tell_room(environment(this_object()),
   "С���ӻ�ͷ�������㣬Ȼ��ܲ�м�ط����ˣ��ݷ��ڼ�Ц�����֪��\n"
   );
   obj=present("pigeon");
   obj->remove();
   return 1;
   }
