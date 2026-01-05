 const user = {
  name: "Rahul",
  show() {
    setTimeout(() => {
      console.log(this.name);
    }, 1000);
  }
};

user.show();
