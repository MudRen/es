#include <mudlib.h>;
#include <config.h>;
 
inherit OBJECT;
inherit DAEMON ;

void create();
void init();
int read_me(string str);
 
void create() {
  seteuid(getuid());
  set("id",({"sutra"}));
  set_name("sutra","��Ͼ�");
  set_short("sutra","��Ͼ�");
  set_long("�Ȿ��Ͼ����������൱����ʷ, ֽ�Ų�������, ���һ��е�ںڵġ�\n"
           "�������Ȿ�����Ȼ����ʷ�ļ�ֵ, �ѹַ����������ӡ�\n");
  set("mass",1);
  set("bulk",1);
  set("unit","��");
  set("no_sale",1);
  set("prevent_drop",1) ;
  set("value",({10,"silver"}) );
}
