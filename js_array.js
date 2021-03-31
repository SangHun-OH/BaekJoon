/**
 * Use the Arrow Function rather than anonymous function, if you can
 */
// 1. Create an Array list containing the following as a literal object.
//title	              price	author	  rank
//----------------------------------------
//Three Little Pigs	  20	  Jacobs	  1
//Alice in Wonderland	25	  Carroll	  2
//Seven Dwarfs	      35	  Disney	  3
//Swallow's gift	    15	  Unknown 	4
let books = [
  {title: "Three Little Pigs", price: 20, author: "Jacobs", rank: 1},
  {title: "Alice in Wonderland", price: 25, author: "Carroll", rank: 2},
  {title: "Seven Dwarfs", price: 35, author: "Disney", rank: 3},
  {title: "Swallow's gift", price: 15, author: "Unknown", rank: 4},
];

let book = {title: "Cinderella", price: 30, author: "Perrault", rank: 5};

// 2. What is the type of books? Are there any Javascript types?

// reference 타입.

//3. Add a book object to the front of books array.

books.unshift(book);
//console.log(books);


//4. Delete the book object you just added.

books.shift();
//console.log(books);

// 5. Add a book object to the end of books array

books.push(book);
//console.log(books);

// 6. Delete the book object you just added.

books.pop();
//console.log(books);

// 7. Insert a book object between Alice in Wonderland and Seven Dwarfs. 

books.splice(2,0,book);
//console.log(books);

// 8. Delete the book object you just added.

books.splice(2,1);
//console.log(books);

// 9. 제목이 Swallow's gift인 객체의 작가를 Unknown 에서 Tom 으로 변경하시오.
// 먼저 Swallow's gift 를 찾은 후에 이름을 변경하시오.

const b = books.find(function(item){
  if (item.title === "Swallow's gift"){
    return true;
  }
})
b.author = 'Tom';
//console.log(books);

// 10. Sum all the price of books array.

let sum = 0;
books.forEach(item => sum+= item.price);
//console.log(books);

// 11. rank가 3보다 적은 책들을 모은 새로운 배열을 리턴하시오.

const highRankList = books.filter(item => item.rank <3);
//console.log(highRankList);

// 12. After sorting the title first, create a new array with a rank number before a title
// the result is

const rankTitle = [...books]
.sort((a,b) => {
  if (a.title > b.title){
    return 1;
  } else if (a.title < b.title){
    return -1;
  } else{
    return 0;
  }
})
.map((item,index)=> `${index+1}. ${item.title}`)

//console.log(rankTitle)


// 13. 가장 비싼 책의 제목을 출력하시오.

const exTitle = [...books]
.sort((a,b) => {
  if (a.price > b.price){
    return 1;
  } else if (a.price < b.price){
    return -1;
  } else{
    return 0;
  }
})

//console.log(exTitle)

const exBook = exTitle.pop();
console.log(exBook.title);