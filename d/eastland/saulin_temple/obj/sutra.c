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
  set_name("sutra","楞枷经");
  set_short("sutra","楞枷经");
  set_long("这本楞枷经看来已有相当的历史, 纸张不但泛黄, 而且还有点黑黑的。\n"
           "你心想这本经书果然有历史的价值, 难怪方丈这麽重视。\n");
  set("mass",1);
  set("bulk",1);
  set("unit","本");
  set("no_sale",1);
  set("prevent_drop",1) ;
  set("value",({10,"silver"}) );
}
