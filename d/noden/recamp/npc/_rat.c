
#include <mudlib.h>
void create(object ob)
{
        if (!ob) return ;
        seteuid(getuid()) ;
	ob->set_level(2);
	ob->set_name( "mi rat", "������" );
	ob->add( "id", ({ "rat","mi rat" }) );
	ob->set_short( "������" );
	ob->set_long(
	 "�㿴��һֻ�Һ�ɫ�������������ϵء�֨֨���ҽС�\n"
	);
	ob->set( "unit", "ֻ" );
	ob->set( "alignment", -100 );
	ob->set_c_verbs( ({ "%s�ſ�������%s����һҧ" }) );
	ob->set_c_limbs( ({ "ͷ��", "����", "�Ȳ�" }) );
        ob->set("chat_chance",5) ;
        ob->set("att_chat_output",
          ({"������˵:����ѽ! ��è�۸�������? �����㻹Ҫ�ҵ���!!\n",
            "������˵:����è! ��͵Ц! ������ͻ���������!!\n"})) ;
}
