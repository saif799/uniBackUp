const del = document.querySelector("table");

//this one does work but it does take a bit more time it cycles threw the whole new table after we deleted the selected tr and resset the number of all the tablerows that exist in there

/////////////////////////////////////////////////////////////////////////////////////

// function reset(newtablerows) {
//   for (let i = 1; i <= newtablerows.length; i++) {
//     if (newtablerows.classList.contains("hidden"))
//       newtablerows[i].children[0].textContent = i;
//   }
// }

// del.addEventListener("click", (e) => {
//   if (e.target.className === "deleteBtn") {
//     const tr = e.target.parentElement;
//     tr.parentElement.removeChild(tr);
//     const newAllTrs = document.querySelectorAll("tr");
//     reset(newAllTrs);
//   }
// });
///////////////////////////////////////////////////////////////////////////////////////

//while this one takes the value of the table row we want to delete and gives it to its next sibling and then modify all the num of all the left siblings (table rows ) after it till it cant find no siblings this one is probably better since it dosnt cycle threw the whole table again it only change the value of the elements that there value need to be changed  so it takes less time but it does have one extra variable

function resetsibling(current, i) {
  if (current != null) {
    current.children[0].textContent = i;
    i++;
    resetsibling(current.nextElementSibling, i);
  }
}

////////////////////////////////////////////////////////////////////////

function resetihdden(tablerow, i) {
  if (tablerow) {
    if (!tablerow.classList.contains("hidden")) {
      tablerow.children[0].textContent = i;
      i++;
    }
    resetihdden(tablerow.nextElementSibling, i);
  }
}

del.addEventListener("click", (e) => {
  if (e.target.className === "deleteBtn") {
    const tr = e.target.parentElement;
    let i = tr.children[0].textContent;
    const nextSibling = tr.nextElementSibling;
    tr.parentElement.removeChild(tr);
    resetsibling(nextSibling, i);
  }
});

//search
const searchField = document.getElementById("search");
searchField.addEventListener("keyup", (e) => {
  const students = document.getElementsByTagName("tr");
  const find = e.target.value;

  const start = Array.from(students);
  start.forEach((student) => {
    const studentName = student.children[1].textContent;
    if (studentName.indexOf("Full name") == -1) {
      if (studentName.toLowerCase().indexOf(find) == -1) {
        student.classList.add("hidden");
      } else {
        student.classList.remove("hidden");
      }
    }
  });

  //change the num of the found tr's
  //   resetihdden(start[1], 1);
});
