#include <linux/module.h>
#include <linux/kernel.h>
#include <linux/init.h>

static int __init start(void) {
	printk(KERN_INFO "...Loading module ...\n");
	printk(KERN_INFO "I am loaded\n");
	return 0;
}

static void __exit end(void) {
	printk(KERN_INFO "Bye,I am unloaded\n");
}
module_init(start);
module_exit(end);
